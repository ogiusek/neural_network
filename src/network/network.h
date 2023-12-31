#ifndef TYPE_NETWORK_H
#define TYPE_NETWORK_H

#include "./column.cpp"
#include "./utils/include.h"

#include <cstring>

// test diffrent cost functions
// test diffrent activations functions

class NeuralNetwork
{
public:
  int *columnsInitializer;
  int columnsAmount;
  NeuralColumn *columns;

  void randomize(double weightLimit = 1.0, double biasLimit = 1.0);

  double *activate(double *values);
  void train(double **inputs, double **expectedOutputs, double learningRate, int batchSize);

  NeuralNetwork(int *_columns);
  ~NeuralNetwork();
};

#endif