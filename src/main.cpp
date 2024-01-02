#include "./main.h"

using namespace std;

int inputsAmount = 25;
float **inputs = new float *[inputsAmount]
{
  new float[2]{0.0, 0.0},
      new float[2]{50.0, 0.0},
      new float[2]{0.0, 50.0},
      new float[2]{50.0, 50.0},

      new float[2]{100.0, 0.0},
      new float[2]{0.0, 100.0},
      new float[2]{100.0, 50.0},
      new float[2]{50.0, 100.0},
      new float[2]{100.0, 100.0},

      new float[2]{150.0, 0.0},
      new float[2]{0.0, 150.0},
      new float[2]{150.0, 50.0},
      new float[2]{50.0, 150.0},
      new float[2]{150.0, 100.0},
      new float[2]{100.0, 150.0},
      new float[2]{150.0, 150.0},

      new float[2]{200.0, 0.0},
      new float[2]{0.0, 200.0},
      new float[2]{200.0, 50.0},
      new float[2]{50.0, 200.0},
      new float[2]{200.0, 100.0},
      new float[2]{100.0, 200.0},
      new float[2]{200.0, 150.0},
      new float[2]{150.0, 200.0},
      new float[2]{200.0, 200.0},
};
float **expectedOutputs = new float *[inputsAmount] // everything what is not above 150 should be 1.0, 0.0 else 0.0, 1.0
{
  new float[2]{1.0, 0.0},
      new float[2]{1.0, 0.0},
      new float[2]{1.0, 0.0},
      new float[2]{1.0, 0.0},

      new float[2]{1.0, 0.0},
      new float[2]{1.0, 0.0},
      new float[2]{1.0, 0.0},
      new float[2]{1.0, 0.0},
      new float[2]{1.0, 0.0},

      new float[2]{1.0, 0.0},
      new float[2]{1.0, 0.0},
      new float[2]{1.0, 0.0},
      new float[2]{1.0, 0.0},
      new float[2]{1.0, 0.0},
      new float[2]{1.0, 0.0},
      new float[2]{1.0, 0.0},

      new float[2]{0.0, 1.0},
      new float[2]{0.0, 1.0},
      new float[2]{0.0, 1.0},
      new float[2]{0.0, 1.0},
      new float[2]{0.0, 1.0},
      new float[2]{0.0, 1.0},
      new float[2]{0.0, 1.0},
      new float[2]{0.0, 1.0},
      new float[2]{0.0, 1.0},
};

int main()
{
  cout << "Hello World\n";

  int weightLimit = 1,
      biasLimit = 1;

  int *columns = new int[3]{2, 3, 2};                  // network structure
  NeuralNetwork *network = new NeuralNetwork(columns); // create network

  network->randomize(weightLimit, biasLimit);                                  // randomize network
  vector<Slider> sliders = getNetworkSliders(network, weightLimit, biasLimit); // get network sliders

  Window window(1280, 720, "title"); // create window
  Inputs windowInputs;               // create window inputs
  Fps fps(60);                       // create window fps
  bool running = 1;

  function<void(void)> trainFunc = [&network, &window]() -> void
  {
    int maxX = window.w / 2, maxY = window.h / 2;
    float **processedInputs = new float *[inputsAmount];
    float **outputs = new float *[inputsAmount];
    for (int i = 0; i < inputsAmount; i++)
    {
      processedInputs[i] = new float[2];
      processedInputs[i][0] = (inputs[i][0] + 0) / maxX;
      processedInputs[i][1] = (inputs[i][1] + 0) / maxY;
      outputs[i] = new float[2];
      outputs[i][0] = expectedOutputs[i][0];
      outputs[i][1] = expectedOutputs[i][1];
    }
    network->train(processedInputs, outputs, 0.1, inputsAmount);

    for (int i = 0; i < inputsAmount; i++) // clear memory
      delete[] outputs[i];
    delete[] processedInputs, outputs;
  };
  Button trainBtn = {500, 10, 100, 30, trainFunc};
  trainBtn.bgColor = {200, 200, 255, 255};
  trainBtn.text = TEXT("Train");

  while (running) // main loop (made each frame)
  {
    fps.MakeNewFrame();                             // wait for frame
    running = windowInputs.loadInputs();            // load inputs
    if (!running || windowInputs.keyboardHolds(27)) // exit if esc is pressed
      break;

    // perform frame
    trainBtn.Update(windowInputs);
    for (Slider &slider : sliders) // update sliders
      slider.Update(windowInputs);

    SDL_RenderClear(window.renderer);                            // clear window
    SDL_SetRenderDrawColor(window.renderer, 255, 255, 255, 255); // draw background
    SDL_Rect rect = {0, 0, window.w, window.h};
    SDL_RenderFillRect(window.renderer, &rect);

    int maxX = window.w / 2, maxY = window.h / 2;
    for (int x = 0; x < maxX; x++) // draw network outputs
      for (int y = 0; y < maxY; y++)
      {
        Array<float> input(new float[2]{(float)x / maxX, (float)y / maxY}, 2);                                         // create input
        Array<float> output = {network->activate(input.data), network->columnsInitializer[network->columns.size - 1]}; // activate network
        int outputColor = output[0] > output[1] ? 1 : 0;                                                               // calculate output color
        SDL_Color color = {Uint8(255 * outputColor), 0, Uint8(255 * (1 - outputColor)), 255};                          // set color
        SDL_SetRenderDrawColor(window.renderer, color.r, color.g, color.b, color.a);                                   // set color
        SDL_RenderDrawPoint(window.renderer, x + window.w / 2, y + window.h / 2);                                      // draw point
      }

    for (int input = 0; input < inputsAmount; input++) // draw expected points
    {
      int x = (int)inputs[input][0] + window.w / 2; // set input as x and y
      int y = (int)inputs[input][1] + window.h / 2;
      bool color = expectedOutputs[input][0] > expectedOutputs[input][1];              // calculate expected color
      SDL_Rect rect = {x - 5, y - 5, 10, 10};                                          // set rect
      SDL_SetRenderDrawColor(window.renderer, color * 200, 0, (1 - color) * 200, 255); // set color
      SDL_RenderFillRect(window.renderer, &rect);
    }

    // show fps
    TEXT(0, 0, "FPS: " + to_string(fps.getFps()), 24).Draw(window.renderer);

    // draw slider
    for (Slider &slider : sliders)
      slider.Draw(window.renderer);
    trainBtn.Draw(window.renderer);

    SDL_RenderPresent(window.renderer);
  }

  return 0;
}
