float countCost(float *output, float *expected, int columnsAmount)
{
  float cost = 0.0;
  for (int i = 0; i < columnsAmount; i++)
    cost += (expected[i] - output[i]) * (expected[i] - output[i]);
  return cost;
}