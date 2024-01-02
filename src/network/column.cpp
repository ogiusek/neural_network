#include <iostream>
#include "./column.h"

// double Neuron::getActivationDerivative(double *values)
// {
//   double sum = bias;
//   for (int i = 0; i < inputs; i++)
//     sum += values[i] * weights[i];
//   return sum;
// }
// double Neuron::activationFunction(double value) { return 1.0 / (1.0 + std::exp(-value)); }
// double Neuron::activate(double *values) { return activationFunction(getActivationDerivative(values)); }

void NeuralColumn::randomize(float weightLimit, float biasLimit)
{
  for (int i = 0; i < neurons.size; i++)
    neurons[i].randomize(weightLimit, biasLimit);
}

float *NeuralColumn::activate(float *values)
{
  float *sum = new float[neurons.size];
  for (int i = 0; i < neurons.size; i++)
    sum[i] = neurons[i].activate(values);
  delete[] values;
  return sum;
}

NeuralColumn::NeuralColumn() : neurons(0){};
NeuralColumn::NeuralColumn(int _inputsAmount, int _neuronsAmount)
    : neurons(_neuronsAmount)
{
  if (neurons.size == 0)
    throw std::runtime_error("Neurons amount can't be 0");

  for (int i = 0; i < neurons.size; i++)
    neurons[i] = Neuron(_inputsAmount);
}

NeuralColumn::~NeuralColumn(){};
