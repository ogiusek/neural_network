#ifndef TYPE_NEURON_H
#define TYPE_NEURON_H
#include <math.h>
#include <random>
#include <chrono>
#include <vector>

#include "../utils/include.h"

class Neuron
{
private:
  float getActivationDerivative(float *inputs);
  float activationFunction(float input);

public:
  Array<float> weights;
  float bias;

  void randomize(float weightLimit, float biasLimit);
  float activate(float *inputs);

  Neuron(int _inputs);
  Neuron();
  ~Neuron();
};

#endif