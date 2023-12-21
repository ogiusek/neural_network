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

void NeuralNetwork::randomize()
{
  for (int i = 0; i < columnsAmount; i++)
    columns[i].randomize();
}

double *NeuralNetwork::activate(double *values)
{
  double *sum = values;
  for (int i = 0; i < columnsAmount; i++)
    sum = columns[i].activate(sum);
  return sum;
}

Neuron **NeuralNetwork::getAllNeurons()
{
  int neuronsAmount = 0;
  for (int i = 0; i < columnsAmount; i++)
    neuronsAmount += columns[i].neuronsAmount;
  Neuron **result = new Neuron *[neuronsAmount];
  for (int i = 0; i < columnsAmount; i++)
    for (int j = 0; j < columns[i].neuronsAmount; j++)
      result[i * columns[i].neuronsAmount + j] = &columns[i].neurons[j];
  return result;
}

void NeuralNetwork::train(double **inputs, double **expectedOutputs, double learningRate, int batchSize)
{
  copyToNew();
  Neuron **neurons = getAllNeurons();
  for (int batch = 0; batch < batchSize; batch++)
  {
    double *input = inputs[batch];
    double *expectedOutput = expectedOutputs[batch];
    double originalScore = countCost(activate(input), expectedOutput, columnsInitializer[columnsAmount - 1]);

    for (int i = 0; neurons[i] != nullptr; i++)
    {
      Neuron &neuron = *neurons[i];

      for (int w = 0; w < neuron.inputs; w++)
      {
        neuron.weights[w] += learningRate;
        double newScore = countCost(activate(input), expectedOutput, columnsInitializer[columnsAmount - 1]);
        neuron.weights[w] -= learningRate;
        double delta = (newScore - originalScore) / learningRate;
        neuron.newWeights[w] -= learningRate * delta / batchSize;
      }

      // neuron.bias += learningRate;
      // double newScore = countCost(activate(input), expectedOutput, columnsInitializer[columnsAmount - 1]);
      // neuron.bias -= learningRate;
      // double delta = (newScore - originalScore) / learningRate;
      // neuron.newBias -= learningRate * delta / batchSize;
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
    columns[i] = NeuralColumn(_columns[i], _columns[i + 1], 1);
}

NeuralNetwork::~NeuralNetwork()
{
  for (int i = 0; i < columnsAmount; i++)
    columns[i].free();

  delete[] columns;
  delete[] columnsInitializer;
}