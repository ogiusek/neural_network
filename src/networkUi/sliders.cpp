#include <vector>
#include <string>

#include "./include.h"

std::vector<Slider> getNetworkSliders(NeuralNetwork *network, float sliderWeightLimit, float sliderBiasLimit)
{
  std::vector<Slider> sliders;
  int biases = 1, weights = 1;
  for (int l = 0; l < network->columns.size; l++)
    for (int n = 0; n < network->columns[l].neurons.size; n++)
    {
      for (int w = 0; w < network->columns[l].neurons[n].weights.size; w++)
      { // add weight slider
        Slider slider(-sliderWeightLimit, sliderWeightLimit, 32, 0);
        slider.bgColor = {224, 224, 224, 255};
        slider.knobColor = {0, 0, 0, 255};
        slider.knobTextColor = {0, 0, 0, 255};
        slider.assign = &network->columns[l].neurons[n].weights[w];
        slider.y = 32 * (sliders.size() + 1);
        slider.comment = TEXT(slider.x, slider.y, "W " + std::to_string(weights++), slider.h);
        sliders.push_back(slider);
      } // add bias slider
      Slider slider(-sliderBiasLimit, sliderBiasLimit, 32, 0);
      slider.bgColor = {224, 224, 224, 255};
      slider.knobColor = {0, 0, 0, 255};
      slider.knobTextColor = {0, 0, 0, 255};
      slider.assign = &network->columns[l].neurons[n].bias;
      slider.y = 32 * (sliders.size() + 1);
      slider.comment = TEXT(slider.x, slider.y, "B " + std::to_string(biases++), slider.h);
      sliders.push_back(slider);
    }
  return sliders;
}