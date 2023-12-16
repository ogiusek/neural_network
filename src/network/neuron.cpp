#include "neuron.h"

double Neuron::getActivationDerivative(double *values)
{
  double sum = bias;
  for (int i = 0; i < inputs; i++)
    sum += values[i] * weights[i];
  return sum;
}

void Neuron::copyToNew()
{
  newWeights = new double[inputs];
  for (int i = 0; i < inputs; i++)
    newWeights[i] = weights[i];
  newBias = bias;
}

void Neuron::implementChanges()
{
  for (int i = 0; i < inputs; i++)
  {
    auto _newWeight = newWeights[i];
    newWeights[i] = weights[i];
    weights[i] = _newWeight;
  }
  auto _newBias = newBias;
  newBias = bias;
  bias = _newBias;
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
      bias(0.0)
{
  for (int i = 0; i < inputs; i++)
    weights[i] = 0.0;
};