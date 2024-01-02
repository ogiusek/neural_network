#ifndef TYPE_NEURAL_COLUMN_H
#define TYPE_NEURAL_COLUMN_H

#include <vector>
#include <random>
#include <chrono>

// #include "../utils/include.h"
#include "./neuron.cpp"

class NeuralColumn
{
private:
public:
  Array<Neuron> neurons;
  void randomize(float weightLimit, float biasLimit); // randomize weights and biases
  float *activate(float *values);                     // activate column

  NeuralColumn(int _inputsAmount, int _neuronsAmount);
  NeuralColumn();
  ~NeuralColumn();
};

#endif