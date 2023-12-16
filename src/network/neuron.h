#ifndef TYPE_NEURON_H
#define TYPE_NEURON_H
#include <math.h>

class Neuron
{
private:
  double *newWeights;
  double newBias;
  double getActivationDerivative(double *values);

public:
  int inputs;
  double *weights;
  double bias;

  void copyToNew();
  void implementChanges();
  double activate(double *values);

  Neuron(int _inputs);
  Neuron();
  ~Neuron();
};

#endif