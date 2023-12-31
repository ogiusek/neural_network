#include "neuron.h"

void Neuron::randomize(double weightLimit, double biasLimit)
{
  std::uniform_real_distribution<double> weightRandomizer(-weightLimit, weightLimit);
  for (int i = 0; i < inputs; i++)
  { // generate weights
    std::default_random_engine re(std::chrono::system_clock::now().time_since_epoch().count());
    weights[i] = weightRandomizer(re);
  } // generate bias
  std::uniform_real_distribution<double> biasRandomizer(-weightLimit, weightLimit);
  std::default_random_engine re(std::chrono::system_clock::now().time_since_epoch().count());
  bias = biasRandomizer(re);
};

double Neuron::getActivationDerivative(double *values)
{
  double sum = bias;
  for (int i = 0; i < inputs; i++)
    sum += values[i] * weights[i];
  return sum;
}
double Neuron::activationFunction(double value) { return 1.0 / (1.0 + std::exp(-value)); }
double Neuron::activate(double *values) { return activationFunction(getActivationDerivative(values)); }

Neuron::Neuron(){};
Neuron::Neuron(int _inputs, bool _partOfColumn)
    : inputs(_inputs),
      weights(new double[_inputs]),
      bias(0.0),
      partOfColumn(_partOfColumn)
{
  for (int i = 0; i < inputs; i++)
    weights[i] = 0.0;
};

void Neuron::free()
{
  delete[] weights;
}

Neuron::~Neuron()
{
  if (!partOfColumn)
    free();
};