#include "./array.h"

// = operator
template <typename T>
Array<T> &Array<T>::operator=(const Array &arr)
{
  if (this != &arr)
  {
    delete[] data;
    size = arr.size;
    data = new T[arr.size];
    for (int i = 0; i < size; i++)
      data[i] = arr.data[i];
  }
  return *this;
}

template <typename T>
Array<T>::Array(const Array<T> &arr) { operator=(arr); };

//

template <typename T> // allocate initializer
Array<T>::Array(int _size) : size(_size), data(new T[_size]){};

template <typename T>
Array<T>::Array(T e, int _size) : size(_size), data(new T[_size]) { fill(e); };

template <typename T> // array parse
Array<T>::Array(T *arr)
{
  int i = 0;
  while (data[i] != T())
    i++;
  Array(arr, i);
};

template <typename T> // array initializer
Array<T>::Array(T *arr, int _size) : data(new T[_size]), size(_size)
{
  for (int i = 0; i < _size; i++)
    data[i] = arr[i];
};

template <typename T>
Array<T>::Array(std::initializer_list<T> arr) : size(arr.size()), data(new T[arr.size()])
{
  int i = 0;
  for (auto it = arr.begin(); it != arr.end(); it++, i++)
    data[i] = *it;
};

template <typename T> // empty initializer
Array<T>::Array() : data(nullptr), size(0){};