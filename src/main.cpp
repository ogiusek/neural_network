#include <iostream>
#include <math.h>

#include "./network/include.h"

using namespace std;

int main()
{
  cout << "Hello World\n";

  // test neural network
  int *columns = new int[2]{1, 1};
  NeuralNetwork *network = new NeuralNetwork(columns);
  // double *result = network->activate(new double[2]{0, 0});
  // int resultSize = network->columns[network->columnsAmount - 1].neuronsAmount;
  // for (int i = 0; i < resultSize; i++)
  //   cout << result[i] << endl;

  double **inputs = new double *[2];
  inputs[1] = new double[1]{-1};
  inputs[0] = new double[1]{1};
  double **outputs = new double *[2];
  outputs[1] = new double[1]{1};
  outputs[0] = new double[1]{-1};

  for (int i = 0; i < 10000; i++)
  {
    for (int i = 0; i < 2; i++)
    {
      double *result = network->activate(inputs[i]);
      int resultSize = network->columns[network->columnsAmount - 1].neuronsAmount;
      for (int i = 0; i < resultSize; i++)
        cout << result[i] << endl;

      network->train(inputs[i], outputs[i], 0.1);
    }
    cout << "\n\n\n\n";
  }

  for (int i = 0; i < 2; i++)
  {
    double *result = network->activate(inputs[i]);
    int resultSize = network->columns[network->columnsAmount - 1].neuronsAmount;
    for (int i = 0; i < resultSize; i++)
      cout << result[i] << endl;

    network->train(inputs[i], outputs[i], 0.1);
  }

  cout << "bias:" << network->columns[0].neurons[0].bias
       << "\nweights:" << network->columns[0].neurons[0].weights[0] << endl;

  // test neural network
  // NeuralNetwork *network = new NeuralNetwork();

  return 0;
}
