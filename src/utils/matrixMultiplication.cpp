#include "./include.h"

namespace Utils
{
  template <typename T>
  Array<Array<T>> matrixMultiplication(Array<Array<T>> a, Array<Array<T>> b)
  {
    if (a[0].size != b.size)
      throw std::runtime_error("Invalid matrix sizes");

    Array<Array<T>> result(a.size);
    for (int i = 0; i < a.size; i++)
    {
      result[i] = Array<T>(b[0].size);
      for (int j = 0; (j < b[0].size); j++)
      {
        result[i][j] = 0;
        for (int k = 0; (k < a[0].size) && (k < b.size); k++)
          result[i][j] += a[i][k] * b[k][j];
      }
    }

    return result;
  }
};