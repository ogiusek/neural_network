#include "neuron.h"

void Neuron::copyToNew()
{
  newBias = bias;
  for (int i = 0; i < inputs; i++)
    newWeights[i] = weights[i];
}
void Neuron::implementChanges()
{
  bias = newBias;
  for (int i = 0; i < inputs; i++)
    weights[i] = newWeights[i];
}

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
Neuron::Neuron(int _inputs)
    : inputs(_inputs),
      weights(new double[_inputs]),
      newWeights(new double[_inputs]),
      bias(0.0)
{
  for (int i = 0; i < inputs; i++)
    weights[i] = 0.0;
};
Neuron::~Neuron(){};