#include "./include.h"

namespace Utils
{
  template <typename T>
  Array<Array<T>> transpose(Array<Array<T>> array)
  {
    Array<Array<T>> result(array[0].size);

    for (int i = 0; i < result.size; i++)
    {
      result[i] = Array<T>(array.size);
      for (int j = 0; j < result[i].size; j++)
        result[i][j] = array[j][i];
    }

    return result;
  }
};