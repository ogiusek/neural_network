#include "./array.h"

// array operators

template <typename T>
Array<T> Array<T>::operator+(const Array<T> &arr)
{
  Array<T> temp(*this);
  for (int i = 0; i < size; i++)
    temp.data[i] += arr.data[i];
  return temp;
};

template <typename T>
Array<T> Array<T>::operator-(const Array<T> &arr)
{
  Array<T> temp(*this);
  for (int i = 0; i < size; i++)
    temp.data[i] -= arr.data[i];
  return temp;
};

template <typename T>
Array<T> Array<T>::operator*(const Array<T> &arr)
{
  Array<T> temp(*this);
  for (int i = 0; i < size; i++)
    temp.data[i] *= arr.data[i];
  return temp;
};

template <typename T>
Array<T> Array<T>::operator/(const Array<T> &arr)
{
  Array<T> temp(*this);
  for (int i = 0; i < size; i++)
    temp.data[i] /= arr.data[i];
  return temp;
};

// operator+-*/=
template <typename T>
void Array<T>::operator+=(const T &e) { *this = (*this + Array<T>(e, size)); };
template <typename T>
void Array<T>::operator-=(const T &e) { *this = (*this - Array<T>(e, size)); };
template <typename T>
void Array<T>::operator*=(const T &e) { *this = (*this * Array<T>(e, size)); };
template <typename T>
void Array<T>::operator/=(const T &e) { *this = (*this / Array<T>(e, size)); };

// single element operators
template <typename T>
Array<T> Array<T>::operator+(const T &e) { return *this + Array<T>(e, size); };
template <typename T>
Array<T> Array<T>::operator-(const T &e) { return *this - Array<T>(e, size); };
template <typename T>
Array<T> Array<T>::operator*(const T &e) { return *this * Array<T>(e, size); };
template <typename T>
Array<T> Array<T>::operator/(const T &e) { return *this / Array<T>(e, size); };

// single element operator+-*/=
template <typename T>
void Array<T>::operator+=(const Array<T> &e) { *this = (*this + e); };
template <typename T>
void Array<T>::operator-=(const Array<T> &e) { *this = (*this - e); };
template <typename T>
void Array<T>::operator*=(const Array<T> &e) { *this = (*this * e); };
template <typename T>
void Array<T>::operator/=(const Array<T> &e) { *this = (*this / e); };