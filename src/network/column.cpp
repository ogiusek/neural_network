#include <iostream>
#include "./column.h"

void NeuralColumn::randomize(float weightLimit, float biasLimit)
{
  for (int i = 0; i < neurons.size; i++)
    neurons[i].randomize(weightLimit, biasLimit);
}

float *NeuralColumn::activate(float *inputs)
{
  float *sum = new float[neurons.size];
  for (int i = 0; i < neurons.size; i++)
    sum[i] = neurons[i].activate(inputs);

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
