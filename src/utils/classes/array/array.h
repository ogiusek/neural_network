#ifndef TYPE_ARRAY
#define TYPE_ARRAY

#include <initializer_list>

template <typename T>
struct Array
{
  T *data = nullptr; // array
  int size = 0;      // array size

  T &operator[](int index); // returns element in array

  Array operator+(const Array &arr); // addition
  Array operator-(const Array &arr); // subtraction
  Array operator*(const Array &arr); // multiplication
  Array operator/(const Array &arr); // division

  Array operator+(const T &arr); // addition
  Array operator-(const T &arr); // subtraction
  Array operator*(const T &arr); // multiplication
  Array operator/(const T &arr); // division

  void fill(T e); // fill array with one element

  Array &operator=(const Array &arr); // assignment
  Array(const Array<T> &arr);         // copy initializer

  explicit Array(int _size);           // allocate memory
  explicit Array(T e, int _size);      // allocate and fill
  explicit Array(T *arr);              // array parse
  explicit Array(T *arr, int _size);   // array parse
  Array(std::initializer_list<T> arr); // list initializer
  Array();                             // default

  ~Array();
};

#endif