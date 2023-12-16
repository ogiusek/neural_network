#include "./network.h"

void NeuralNetwork::copyToNew()
{
  for (int i = 0; i < columnsAmount; i++)
    columns[i].copyToNew();
}

void NeuralNetwork::implementChanges()
{
  for (int i = 0; i < columnsAmount; i++)
    columns[i].implementChanges();
}

double *NeuralNetwork::activate(double *values)
{
  double *sum = values;
  for (int i = 0; i < columnsAmount; i++)
    sum = columns[i].activate(sum);
  return sum;
}

void NeuralNetwork::train(double *input, double *expectedOutput)
{
  copyToNew();
  double *originalScore = activate(input);

  for (int i = 0; i < columnsAmount; i++)
  {
    for (int j = 0; j < columns[i].neuronsAmount; j++)
    {
      Neuron &neuron = columns[i].neurons[j];
        }
  }
  implementChanges();
}

NeuralNetwork::NeuralNetwork(int *_columns) : columnsInitializer(_columns)
{
  int _columnsAmount = 0;
  while (_columns[_columnsAmount] != 0)
    _columnsAmount++;
  columnsAmount = _columnsAmount - 1;

  if (columnsAmount == 0)
    throw "Columns amount can't be 0";

  columns = new NeuralColumn[columnsAmount];
  for (int i = 0; i < columnsAmount; i++)
    columns[i] = NeuralColumn(_columns[i], _columns[i + 1]);
}
