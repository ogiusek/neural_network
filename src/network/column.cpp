#include "./column.h"

void NeuralColumn::copyToNew()
{
  for (int i = 0; i < neuronsAmount; i++)
    neurons[i].copyToNew();
}

void NeuralColumn::implementChanges()
{
  for (int i = 0; i < neuronsAmount; i++)
    neurons[i].implementChanges();
}

void NeuralColumn::randomize()
{
  for (int i = 0; i < neuronsAmount; i++)
    neurons[i].randomize();
}

double *NeuralColumn::activate(double *values)
{
  double *sum = new double[neuronsAmount];
  for (int i = 0; i < neuronsAmount; i++)
    sum[i] = neurons[i].activate(values);
  return sum;
}

NeuralColumn::NeuralColumn() : neuronsAmount(0){};
NeuralColumn::NeuralColumn(int _inputsAmount, int _neuronsAmount, bool _partOfNetwork)
    : neuronsAmount(_neuronsAmount),
      neurons(new Neuron[_neuronsAmount]),
      partOfNetwork(_partOfNetwork)
{
  if (neuronsAmount == 0)
    throw "Neurons amount can't be 0";

  for (int i = 0; i < neuronsAmount; i++)
    neurons[i] = Neuron(_inputsAmount, 1);
}

void NeuralColumn::free()
{
  for (int i = 0; i < neuronsAmount; i++)
    neurons[i].free();

  delete[] neurons;
}

NeuralColumn::~NeuralColumn()
{
  if (!partOfNetwork)
    free();
};
