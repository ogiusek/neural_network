#ifndef TYPE_NEURON_H
#define TYPE_NEURON_H
#include <math.h>
#include <random>
#include <chrono>

class Neuron
{
private:
  double getActivationDerivative(double *values);
  double activationFunction(double value);
  bool partOfColumn;

public:
  int inputs;

  double *newWeights;
  double *weights;

  double newBias;
  double bias;

  void copyToNew();
  void implementChanges();
  void randomize(double weightLimit, double biasLimit);

  double activate(double *values);

  Neuron(int _inputs, bool _partOfColumn = 0);
  Neuron();

  void free();
  ~Neuron();
};

#endif