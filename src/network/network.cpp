#include "./network.h"

void NeuralNetwork::randomize(double weightLimit, double biasLimit)
{
  for (int i = 0; i < columnsAmount; i++)
    columns[i].randomize(weightLimit, biasLimit);
}

double *NeuralNetwork::activate(double *values)
{
  double *sum = new double[columnsInitializer[0]];
  memcpy(sum, values, columnsInitializer[0] * sizeof(double));

  for (int i = 0; i < columnsAmount; i++)
    sum = columns[i].activate(sum);
  return sum;
}

void NeuralNetwork::train(double **inputs, double **expectedOutputs, double learningRate, int batchSize)
{
  for (int batch = 0; batch < batchSize; batch++)
  {
    for (int x = 0; x < columnsAmount; x++)
      for (int y = 0; y < columns[x].neuronsAmount; y++)
      {
        Neuron *neuron = &columns[x].neurons[y];
        neuron->randomize(1.0, 1.0);
      }
  }
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
    columns[i] = NeuralColumn(_columns[i], _columns[i + 1], 1);
}

NeuralNetwork::~NeuralNetwork()
{
  for (int i = 0; i < columnsAmount; i++)
    columns[i].free();

  delete[] columns;
  delete[] columnsInitializer;
}