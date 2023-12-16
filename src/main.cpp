#include <iostream>
#include <math.h>

using namespace std;

double countCost(double *output, double *expected)
{
  int columnsAmount = sizeof(output) / sizeof(output[0]);
  double cost = 0.0;
  for (int i = 0; i < columnsAmount; i++)
    cost += (expected[i] - output[i]) * (expected[i] - output[i]);
  return cost;
}

class Neuron
{
private:
  double *newWeights;
  double newBias;
  double getActivationDerivative(double *values)
  {
    double sum = bias;
    for (int i = 0; i < inputs; i++)
      sum += values[i] * weights[i];
    return sum;
  }

public:
  int inputs;
  double *weights;
  double bias;

  void copyToNew()
  {
    newWeights = new double[inputs];
    for (int i = 0; i < inputs; i++)
      newWeights[i] = weights[i];
    newBias = bias;
  }

  void implementChanges()
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

  double activate(double *values)
  {
    double sum = getActivationDerivative(values);
    return 1.0 / (1.0 + exp(-sum));
  }

  Neuron(int _inputs)
      : inputs(_inputs),
        weights(new double[_inputs]),
        bias(0.0)
  {
    for (int i = 0; i < inputs; i++)
      weights[i] = 0.0;
  };
  Neuron() : inputs(0){};
  ~Neuron(){};
};
class NeuralColumn
{
public:
  int neuronsAmount;
  Neuron *neurons;

  void copyToNew()
  {
    for (int i = 0; i < neuronsAmount; i++)
      neurons[i].copyToNew();
  }

  void implementChanges()
  {
    for (int i = 0; i < neuronsAmount; i++)
      neurons[i].implementChanges();
  }

  double *activate(double *values)
  {
    double *sum = new double[neuronsAmount];
    for (int i = 0; i < neuronsAmount; i++)
      sum[i] = neurons[i].activate(values);
    return sum;
  }

  NeuralColumn(int _inputsAmount, int _neuronsAmount)
      : neuronsAmount(_neuronsAmount),
        neurons(new Neuron[_neuronsAmount])
  {
    if (neuronsAmount == 0)
      throw "Neurons amount can't be 0";

    for (int i = 0; i < neuronsAmount; i++)
      neurons[i] = Neuron(_inputsAmount);
  }
  NeuralColumn() : neuronsAmount(0){};
  ~NeuralColumn(){};
};

class NeuralNetwork
{
public:
  int *columnsInitializer;
  int columnsAmount;
  NeuralColumn *columns;

  void copyToNew()
  {
    for (int i = 0; i < columnsAmount; i++)
      columns[i].copyToNew();
  }

  void implementChanges()
  {
    for (int i = 0; i < columnsAmount; i++)
      columns[i].implementChanges();
  }

  double *activate(double *values)
  {
    double *sum = values;
    for (int i = 0; i < columnsAmount; i++)
      sum = columns[i].activate(sum);
    return sum;
  }

  void train(double *input, double *expectedOutput)
  {
    double *sum = activate(input);
    // implementChanges();
  }

  NeuralNetwork(int *_columns) : columnsInitializer(_columns)
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
};

int main()
{
  cout << "Hello World" << endl;

  // test neural network
  int *columns = new int[3]{2, 64, 3};
  NeuralNetwork *network = new NeuralNetwork(columns);
  double *result = network->activate(new double[2]{0, 0});
  int resultSize = network->columns[network->columnsAmount - 1].neuronsAmount;
  for (int i = 0; i < resultSize; i++)
    cout << result[i] << endl;

  // test neural network
  // NeuralNetwork *network = new NeuralNetwork();

  return 0;
}
