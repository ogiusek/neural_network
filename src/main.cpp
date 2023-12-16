#include <iostream>
#include <math.h>

#include "./network/network.cpp"

using namespace std;

int main()
{
  cout << "Hello World\n";

  // test neural network
  int *columns = new int[3]{2, 64, 3};
  NeuralNetwork *network = new NeuralNetwork(columns);
  double *result = network->activate(new double[2]{0, 0});
  int resultSize = network->columns[network->columnsAmount - 1].neuronsAmount;
  for (int i = 0; i < resultSize; i++)
    cout << result[i] << endl;

  // test neural network
  // NeuralNetwork *network = new NeuralNetwork();

  return 0;
}
