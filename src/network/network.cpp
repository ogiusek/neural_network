#include "./network.h"

void NeuralNetwork::randomize(float weightLimit, float biasLimit)
{
  for (int i = 0; i < columns.size; i++)
    columns[i].randomize(weightLimit, biasLimit);
}

float *NeuralNetwork::activate(float *values)
{
  float *sum = new float[columnsInitializer[0]];
  memcpy(sum, values, columnsInitializer[0] * sizeof(float));
  for (int i = 0; i < columns.size; i++)
    sum = columns[i].activate(sum);
  return sum;
}

void NeuralNetwork::train(float **inputs, float **expectedOutputs, float learningRate, int batchSize)
{
  for (int batch = 0; batch < batchSize; batch++)
    for (int x = 0; x < columns.size; x++)
      for (int y = 0; y < columns[x].neurons.size; y++)
      {
        Neuron *neuron = &columns[x].neurons[y];
        neuron->randomize(1.0, 1.0);
      }
}

NeuralNetwork::NeuralNetwork(int *_columns) : columnsInitializer(_columns)
{
  int _columnsAmount = 0; // count columns
  while (_columns[_columnsAmount] != 0)
    _columnsAmount++;

  columns = Array<NeuralColumn>(_columnsAmount - 1); // -1 for input layer

  if (columns.size == 0)
    throw std::runtime_error("Columns amount can't be 0");

  for (int i = 0; i < columns.size; i++)
    columns[i] = NeuralColumn(_columns[i], _columns[i + 1]);
}

NeuralNetwork::~NeuralNetwork()
{
  delete[] columnsInitializer;
}