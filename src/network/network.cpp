#include "./network.h"

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

void NeuralNetwork::train(double *input, double *expectedOutput, double learningRate)
{
  double originalScore = countCost(activate(input), expectedOutput);

  for (int i = 0; i < columnsAmount; i++)
  {
    for (int j = 0; j < columns[i].neuronsAmount; j++)
    {
      Neuron &neuron = columns[i].neurons[j];
      for (int w = 0; w < neuron.inputs; w++)
      {
        neuron.weights[w] += learningRate;
        double newScore = countCost(activate(input), expectedOutput);
        neuron.weights[w] -= learningRate;
        double delta = (newScore - originalScore) / learningRate;
        neuron.newWeights[w] = neuron.weights[w] - learningRate * delta;
      }
      neuron.bias += learningRate;
      double newScore = countCost(activate(input), expectedOutput);
      neuron.bias -= learningRate;
      double delta = (newScore - originalScore) / learningRate;
      neuron.newBias = neuron.bias - learningRate * delta;
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
