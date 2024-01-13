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
void Array<T>::insert(T e)
{
  T *newData = new T[++size];
  memmove(newData + 1, data, (size - 1) * sizeof(T));
  newData[0] = e;
  data = newData;
}

template <typename T>
void Array<T>::push_back(T e)
{
  T *newData = new T[++size];
  memmove(newData, data, (size - 1) * sizeof(T));
  newData[size - 1] = e;
  data = newData;
}

template <typename T>
Array<T>::~Array()
{
  if (clear)
    delete[] data;
};
// i love creating structures which probably exist