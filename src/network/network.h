#ifndef TYPE_NETWORK_H
#define TYPE_NETWORK_H
#include "./column.cpp"
#include "./utils/include.h"

class NeuralNetwork
{
public:
  int *columnsInitializer;
  int columnsAmount;
  NeuralColumn *columns;

  void copyToNew();
  void implementChanges();
  double *activate(double *values);
  void train(double *input, double *expectedOutput);

  NeuralNetwork(int *_columns);
};

#endif