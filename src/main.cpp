#include <iostream>
#include <string>
#include <math.h>

#include "./network/include.h"
#include "./sdl/include.h"
#include "./ui/include.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include <vector>
#include <functional>

using namespace std;

vector<Slider> getNetworkSliders(NeuralNetwork *network, double sliderWeightLimit, double sliderBiasLimit)
{
  vector<Slider> sliders;
  int biases = 1, weights = 1;
  for (int l = 0; l < network->columnsAmount; l++)
    for (int n = 0; n < network->columns[l].neuronsAmount; n++)
    {
      for (int w = 0; w < network->columns[l].neurons[n].inputs; w++)
      { // add weight slider
        Slider slider(-sliderWeightLimit, sliderWeightLimit, 32, 0);
        slider.bgColor = {224, 224, 224, 255};
        slider.knobColor = {0, 0, 0, 255};
        slider.knobTextColor = {0, 0, 0, 255};
        slider.assign = &network->columns[l].neurons[n].weights[w];
        slider.y = 32 * (sliders.size() + 1);
        slider.comment = TEXT(slider.x, slider.y, "W " + to_string(weights++), slider.h);
        sliders.push_back(slider);
      } // add bias slider
      Slider slider(-sliderBiasLimit, sliderBiasLimit, 32, 0);
      slider.bgColor = {224, 224, 224, 255};
      slider.knobColor = {0, 0, 0, 255};
      slider.knobTextColor = {0, 0, 0, 255};
      slider.assign = &network->columns[l].neurons[n].bias;
      slider.y = 32 * (sliders.size() + 1);
      slider.comment = TEXT(slider.x, slider.y, "B " + to_string(biases++), slider.h);
      sliders.push_back(slider);
    }
  return sliders;
}

int main()
{
  cout << "Hello World\n";

  int weightLimit = 1,
      biasLimit = 1;

  int *columns = new int[3]{2, 3, 2};                                          // network structure
  NeuralNetwork *network = new NeuralNetwork(columns);                         // create network
  network->randomize(weightLimit, biasLimit);                                  // randomize network
  vector<Slider> sliders = getNetworkSliders(network, weightLimit, biasLimit); // get sliders

  Window window(1280, 720, "title"); // create window
  Inputs windowInputs;               // create window inputs
  Fps fps(60);                       // create window fps
  bool running = 1;
  while (running) // main loop (made each frame)
  {
    fps.MakeNewFrame();                             // wait for frame
    running = windowInputs.loadInputs();            // load inputs
    if (!running || windowInputs.keyboardHolds(27)) // exit if esc is pressed
      break;

    // perform frame
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
        double *input = new double[2]{(double)x / maxX, (double)y / maxY};                    // create input
        double *output = network->activate(input);                                            // activate network
        int outputColor = output[0] > output[1] ? 1 : 0;                                      // calculate output color
        SDL_Color color = {Uint8(255 * outputColor), 0, Uint8(255 * (1 - outputColor)), 255}; // set color
        delete[] output;                                                                      // delete output
        SDL_SetRenderDrawColor(window.renderer, color.r, color.g, color.b, color.a);          // set color
        SDL_RenderDrawPoint(window.renderer, x + window.w / 2, window.h - y);                 // draw point
      }

    // show fps
    TEXT(0, 0, "FPS: " + std::to_string(fps.getFps()), 24).Draw(window.renderer);

    // draw slider
    for (Slider &slider : sliders)
      slider.Draw(window.renderer);

    SDL_RenderPresent(window.renderer);
  }

  return 0;
}
