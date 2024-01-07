#include "./array.h"
#include "./constructors.cpp"
#include "./special_operators.cpp"

// returns element in array
template <typename T>
T &Array<T>::operator[](int index) { return data[index]; };

template <typename T>
void Array<T>::fill(T e)
{
  for (int i = 0; i < size; i++)
    data[i] = e;
};

template <typename T>
Array<T>::~Array() { delete[] data; };
// i love creating structures which probably exist