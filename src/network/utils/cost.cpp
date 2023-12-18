double countCost(double *output, double *expected, int columnsAmount)
{
  double cost = 0.0;
  for (int i = 0; i < columnsAmount; i++)
    cost += (expected[i] - output[i]) * (expected[i] - output[i]);
  return cost;
}