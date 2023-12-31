#ifndef TYPE_NETWORK_H
#define TYPE_NETWORK_H

#include "./column.cpp"
#include "./utils/include.h"

#include <cstring>

// test diffrent cost functions
// test diffrent activations functions

class NeuralNetwork
{
private:
  // Array<float *> activateFull(float *inputs);
  Array<Array<float>> activateFull(float *inputs);

public:
  Array<int> structure;
  Array<NeuralColumn> columns; // array of neural columns

  void randomize(float weightLimit = 1.0, float biasLimit = 1.0);                                                 // randomize weights and biases
  Array<float> activate(float *inputs);                                                                           // activate column
  void train(Array<Array<float>> inputs, Array<Array<float>> expectedOutputs, float learningRate, int batchSize); // train network

  NeuralNetwork(Array<int> _columns);
  ~NeuralNetwork();
};

#endif