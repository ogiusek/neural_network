#include "neuron.h"

void Neuron::randomize(float weightLimit, float biasLimit) // problem this is to fast and randomizing is the same for many neurons
{
  std::uniform_real_distribution<float> weightRandomizer(-weightLimit, weightLimit);
  for (int i = 0; i < weights.size; i++)
  { // generate weights
    std::default_random_engine re(std::chrono::system_clock::now().time_since_epoch().count());
    weights[i] = weightRandomizer(re);
  } // generate bias
  std::uniform_real_distribution<float> biasRandomizer(-weightLimit, weightLimit);
  std::default_random_engine re(std::chrono::system_clock::now().time_since_epoch().count());
  bias = biasRandomizer(re);
};

float Neuron::getActivationDerivative(float *values)
{
  float sum = bias;
  for (int i = 0; i < weights.size; i++)
    sum += values[i] * weights[i];
  return sum;
}
float Neuron::activationFunction(float value) { return 1.0 / (1.0 + std::exp(-value)); }
// float Neuron::activate(float *values) { return activationFunction(getActivationDerivative(values)); }
float Neuron::activate(float *values) { return 0; }

Neuron::Neuron() : weights(0), bias(0){};
Neuron::Neuron(int _inputs)
    : weights(_inputs),
      bias(0.0){};

Neuron::~Neuron(){};