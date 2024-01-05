#include "./array.h"

// returns element in array
template <typename T>
T &Array<T>::operator[](int index)
{
  return data[index];
};

// returns array
template <typename T>
T *&Array<T>::operator()() { return data; };

// = operator
template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
  if (this == &other)
    return *this;
  delete[] data; // deallocate previous memory block
  size = other.size;
  data = new T[size]; // allocate new memory block
  for (int i = 0; i < size; i++)
    data[i] = other.data[i]; // copy elements from other to current array
  return *this;
}

template <typename T> // vector parse
Array<T>::Array(std::vector<T> arr) : Array(arr.size())
{
  for (int i = 0; i < size; i++)
    data[i] = arr[i];
};

template <typename T>
Array<T>::Array(std::initializer_list<T> arr)
{
  size = arr.size();
  data = new T[size];
  int i = 0;
  for (const T &val : arr)
    data[i++] = val;
};

template <typename T> // array initializer
Array<T>::Array(T *arr, int _size) : data(arr), size(_size){};

template <typename T> // array parse
Array<T>::Array(T *arr) : data(arr)
{
  int i = 0;
  while (data[i] != T())
    i++;
  size = i;
}
template <typename T> // allocate initializer
Array<T>::Array(int _size) : size(_size), data(new T[_size]){};

template <typename T> // empty initializer
Array<T>::Array() : data(nullptr), size(0){};

template <typename T>
void Array<T>::clear()
{
  delete[] data;
  data = nullptr;
}

template <typename T>
Array<T>::~Array()
{
  clear();
};
