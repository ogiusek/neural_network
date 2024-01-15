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
  float *activate(float *inputs);                     // activate column

  void applyDelta(Array<float> delta, Array<float> outputs, float learningRate);
  operator Array<float>();             // get biases
  operator Array<Array<float>>();      // get weights
  void operator=(Array<float>);        // set biases
  void operator=(Array<Array<float>>); // set weights

  NeuralColumn(int _inputsAmount, int _neuronsAmount);
  NeuralColumn();
  ~NeuralColumn();
};

#endif