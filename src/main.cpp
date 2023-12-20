#include <iostream>
#include <math.h>

#include "./network/include.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "./sdl/include.h"
#include "./ui/include.h"

using namespace std;

int main()
{
  cout << "Hello World\n";

  // int *columns = new int[2]{1, 1};
  // NeuralNetwork *network = new NeuralNetwork(columns);

  // double **inputs = new double *[2];
  // inputs[0] = new double[1]{1};
  // inputs[1] = new double[1]{-1};
  // double **outputs = new double *[2];
  // outputs[0] = new double[1]{-1};
  // outputs[1] = new double[1]{1};

  // for (int i = 0; i < 10000; i++)
  //   network->train(inputs, outputs, 1, 2);

  // cout << network->columns[0].neurons[0].weights[0] << endl;
  // cout << network->columns[0].neurons[0].bias << endl;
  // cout << countCost(network->activate(inputs[0]), outputs[0], 1) << endl;
  // cout << countCost(network->activate(inputs[1]), outputs[1], 1) << endl;

  Window window(800, 600, (char *)"title");
  Inputs inputs;
  Fps fps(60);

  Slider slider(-25, 25, 10, 10, 100, 20);

  bool running = 1;
  while (running)
  {
    // wait for frame
    fps.MakeNewFrame();

    // gather input
    running = inputs.loadInputs();
    if (!running || inputs.keyboardHolds(27))
      break;

    // perform frame
    SDL_SetRenderDrawColor(window.renderer, 255, 0, 0, 255);
    SDL_Rect rect = {0, 0, window.w, window.h};
    SDL_RenderFillRect(window.renderer, &rect);

    slider.Update(inputs);
    slider.Draw(window.renderer);
    // DrawText(window.renderer, 0, 0, "Hello World", 32, {0, 0, 0}, Align::CENTER, Align::CENTER);
    // std::cout << slider.getValue() << std::endl;

    SDL_RenderPresent(window.renderer);
  }

  // double **inputs = new double *[6];
  // inputs[0] = new double[4]{0, 0, 1, 1};
  // inputs[1] = new double[4]{0, 1, 0, 1};
  // inputs[2] = new double[4]{0, 1, 1, 0};
  // inputs[3] = new double[4]{1, 0, 0, 1};
  // inputs[4] = new double[4]{1, 0, 1, 0};
  // inputs[5] = new double[4]{1, 1, 0, 0};
  // double **outputs = new double *[6];
  // outputs[0] = new double[2]{0, 1};
  // outputs[1] = new double[2]{0, 1};
  // outputs[2] = new double[2]{1, 0};
  // outputs[3] = new double[2]{1, 0};
  // outputs[4] = new double[2]{0, 1};
  // outputs[5] = new double[2]{0, 1};
  // for (int i = 0; i < 6; i++)
  // {
  //   double *result = network->activate(inputs[i]);
  //   int resultSize = network->columns[network->columnsAmount - 1].neuronsAmount;
  //   for (int i = 0; i < resultSize; i++)
  //     cout << result[i] << endl;
  //   cout << "\n";
  // }
  // cout << "\n\n\n";
  // for (int i = 0; i < 10000; i++)
  //   network->train(inputs, outputs, 10, 2);
  // for (int i = 0; i < 6; i++)
  // {
  //   double *result = network->activate(inputs[i]);
  //   int resultSize = network->columns[network->columnsAmount - 1].neuronsAmount;
  //   for (int i = 0; i < resultSize; i++)
  //     cout << result[i] << endl;
  //   cout << "\n";
  // }
  // Neuron **neurons = network->getAllNeurons();
  // for (int i = 0; neurons[i] != nullptr; i++)
  // {
  //   for (int w = 0; w < neurons[i]->inputs; w++)
  //     cout << neurons[i]->weights[w] << " ";
  //   cout << "\n " << neurons[i]->bias;
  //   cout << "\n\n";
  // }
  // cout << "bias: " << network->columns[0].neurons[0].bias
  //      << "\nweights: " << network->columns[0].neurons[0].weights[0] << endl;

  return 0;
}
