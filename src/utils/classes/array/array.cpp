#include "./array.h"

template <typename T> // get element
T &Array<T>::operator[](int index)
{
  if (index >= size)
    throw std::runtime_error("Out of array size");
  return data[index];
}

// template <typename T> // get array
// T *&Array<T>::operator()()
// {
//   return data;
// };

// template <typename T> // assignment
// void Array<T>::operator=(Array<T> e)
// {
//   ~Array();
//   data = e.data;
//   size = e.size;
// };

template <typename T> // = operator
Array<T> &Array<T>::operator=(const Array &other)
{
  if (this != &other)
  {
    delete[] data; // deallocate previous memory block

    size = other.size;
    data = new T[size]; // allocate new memory block
    for (int i = 0; i < size; i++)
      data[i] = other.data[i]; // copy elements from other to current array
  }
  return *this;
}

template <typename T> // vector parse
Array<T>::Array(std::vector<T> arr) : Array(arr.size())
{
  for (int i = 0; i < size; i++)
    data[i] = arr[i];
};

template <typename T> // default initializer
Array<T>::Array(T *arr, int _size) : data(arr), size(_size){};

template <typename T> // default initializer
Array<T>::Array(T *arr)
{
  data = arr;
  int i = 0;
  while (data[i] == 0)
    i++;
  size = i;
}

template <typename T> // initializers
Array<T>::Array(int _size)
{
  size = _size;
  data = new T[size];
};

template <typename T> // default initializer
Array<T>::Array() : data(nullptr), size(0){};

template <typename T>
Array<T>::~Array()
{
  // std::cout << "array destructor" << std::endl;
  delete[] data;
};
