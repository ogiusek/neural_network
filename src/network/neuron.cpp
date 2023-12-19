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
Neuron::Neuron(int _inputs, bool _partOfColumn)
    : inputs(_inputs),
      weights(new double[_inputs]),
      newWeights(new double[_inputs]),
      bias(0.0),
      partOfColumn(_partOfColumn)
{
  for (int i = 0; i < inputs; i++)
    weights[i] = 0.0;
};

void Neuron::free()
{
  delete[] weights;
  delete[] newWeights;
}

Neuron::~Neuron()
{
  if (!partOfColumn)
    free();
};