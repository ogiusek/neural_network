#include "neuron.h"

&Neuron::operator float() { return bias; }
&Neuron::operator Array<float>() { return weights; }

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

float Neuron::getActivationDerivative(float *inputs)
{
  float sum = bias;
  for (int i = 0; i < weights.size; i++)
    sum += inputs[i] * weights[i];
  return sum;
}
float Neuron::activationFunction(float input) { return 1.0 / (1.0 + std::exp(-input)); }
float Neuron::activate(float *inputs) { return activationFunction(getActivationDerivative(inputs)); }

Neuron::Neuron() : weights(0), bias(0){};
Neuron::Neuron(int _inputs) : weights(_inputs), bias(0.0){};
Neuron::Neuron(Array<float> weights, float bias) : weights(weights), bias(bias){};

Neuron::~Neuron(){};