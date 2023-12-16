#ifndef TYPE_NEURAL_COLUMN_H
#define TYPE_NEURAL_COLUMN_H
#include "neuron.cpp"

class NeuralColumn
{
public:
  int neuronsAmount;
  Neuron *neurons;

  void implementChanges();

  double *activate(double *values);

  NeuralColumn(int _inputsAmount, int _neuronsAmount);
  NeuralColumn();
  ~NeuralColumn();
};

#endif