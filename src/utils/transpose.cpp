#include "./include.h"

template <typename T>
Array<Array<T>> transpose(Array<Array<T>> array)
{
  Array<Array<T>> result(array[0].size);
  for (int i = 0; i < array[0].size; i++)
    result[i] = Array<T>(array.size);

  for (int i = 0; i < array.size; i++)
    for (int j = 0; j < array[i].size; j++)
      result[j][i] = array[i][j];

  return result;
}