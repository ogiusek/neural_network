#include <iostream>
#include <string>
#include <math.h>

#include "./network/include.h"
#include "./sdl/include.h"
#include "./ui/include.h"
#include "./networkUi/include.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include <vector>
#include <functional>

using namespace std;

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
