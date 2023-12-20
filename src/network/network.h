#ifndef TYPE_NETWORK_H
#define TYPE_NETWORK_H
#include "./column.cpp"
#include "./utils/include.h"

// test diffrent cost functions
// test diffrent activations functions

class NeuralNetwork
{
public:
  int *columnsInitializer;
  int columnsAmount;
  NeuralColumn *columns;

  void copyToNew();
  void implementChanges();

  Neuron **getAllNeurons();

  double *activate(double *values);

  void train(double **inputs, double **expectedOutputs, double learningRate, int batchSize);

  NeuralNetwork(int *_columns);
  ~NeuralNetwork();
};

#endif