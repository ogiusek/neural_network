#include "./column.cpp"
#include "./utils/include.h"

class NeuralNetwork
{
public:
  int *columnsInitializer;
  int columnsAmount;
  NeuralColumn *columns;

  void copyToNew()
  {
    for (int i = 0; i < columnsAmount; i++)
      columns[i].copyToNew();
  }

  void implementChanges()
  {
    for (int i = 0; i < columnsAmount; i++)
      columns[i].implementChanges();
  }

  double *activate(double *values)
  {
    double *sum = values;
    for (int i = 0; i < columnsAmount; i++)
      sum = columns[i].activate(sum);
    return sum;
  }

  void train(double *input, double *expectedOutput)
  {
    double *sum = activate(input);
    // implementChanges();
  }

  NeuralNetwork(int *_columns) : columnsInitializer(_columns)
  {

    int _columnsAmount = 0;
    while (_columns[_columnsAmount] != 0)
      _columnsAmount++;
    columnsAmount = _columnsAmount - 1;

    if (columnsAmount == 0)
      throw "Columns amount can't be 0";

    columns = new NeuralColumn[columnsAmount];
    for (int i = 0; i < columnsAmount; i++)
      columns[i] = NeuralColumn(_columns[i], _columns[i + 1]);
  }
};
