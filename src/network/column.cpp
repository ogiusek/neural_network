#include "./neuron.cpp"

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
