#include "neuron.h"

double Neuron::getActivationDerivative(double *values)
{
  double sum = bias;
  for (int i = 0; i < inputs; i++)
    sum += values[i] * weights[i];
  return sum;
}

void Neuron::implementChanges()
{
  bias = newBias;
  for (int i = 0; i < inputs; i++)
    weights[i] = newWeights[i];
}

double Neuron::activate(double *values)
{
  double sum = getActivationDerivative(values);
  return 1.0 / (1.0 + std::exp(-sum));
}

Neuron::Neuron() : inputs(0){};
Neuron::~Neuron(){};
Neuron::Neuron(int _inputs)
    : inputs(_inputs),
      weights(new double[_inputs]),
      newWeights(new double[_inputs]),
      bias(0.0)
{
  for (int i = 0; i < inputs; i++)
    weights[i] = 0.0;
};