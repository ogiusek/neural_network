#include "neuron.h"

void Neuron::randomize(float weightLimit, float biasLimit)
{
  auto randomizer = [](float limit) -> float
  {
    std::random_device rd;
    std::default_random_engine re(rd());
    std::uniform_real_distribution<float> randomizer(-limit, limit);
    float randomValue = randomizer(re);
    return randomValue;
  };
  for (int i = 0; i < weights.size; i++)  // set weights
    weights[i] = randomizer(weightLimit); // set bias
  bias = randomizer(biasLimit);
};

float Neuron::getActivationDerivative(float *values)
{
  float sum = bias;
  for (int i = 0; i < weights.size; i++)
    sum += values[i] * weights[i];
  return sum;
}
float Neuron::activationFunction(float value) { return 1.0 / (1.0 + std::exp(-value)); }
float Neuron::activate(float *values) { return activationFunction(getActivationDerivative(values)); }

Neuron::Neuron() : weights(0), bias(0){};
Neuron::Neuron(int _inputs)
    : weights(_inputs),
      bias(0.0){};

Neuron::~Neuron(){};