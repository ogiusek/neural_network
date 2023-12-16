#ifndef TYPE_NEURON_H
#define TYPE_NEURON_H
#include <math.h>

class Neuron
{
private:
  double getActivationDerivative(double *values);

public:
  int inputs;

  double *newWeights;
  double *weights;

  double newBias;
  double bias;

  void implementChanges();
  double activate(double *values);

  Neuron(int _inputs);
  Neuron();
  ~Neuron();
};

#endif