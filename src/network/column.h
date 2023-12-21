#ifndef TYPE_NEURAL_COLUMN_H
#define TYPE_NEURAL_COLUMN_H
#include "neuron.cpp"

class NeuralColumn
{
private:
  bool partOfNetwork;

public:
  int neuronsAmount;
  Neuron *neurons;

  void copyToNew();
  void implementChanges();
  void randomize();

  double *activate(double *values);

  NeuralColumn(int _inputsAmount, int _neuronsAmount, bool _partOfNetwork = 0);
  NeuralColumn();

  void free();
  ~NeuralColumn();
};

#endif