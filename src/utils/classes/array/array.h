#ifndef TYPE_ARRAY
#define TYPE_ARRAY

#include <initializer_list> // initializer_list
#include <string.h>         // memmove
#include <functional>       // std::function

// Not optimal for adding new elements
template <typename T>
struct Array
{
  T *data = nullptr; // array
  bool clear = true;
  int size = 0; // array size

  T &operator[](int index); // returns element in array

  Array operator+(const Array &arr); // addition
  Array operator-(const Array &arr); // subtraction
  Array operator*(const Array &arr); // multiplication
  Array operator/(const Array &arr); // division

  void operator+=(const Array &arr); // addition
  void operator-=(const Array &arr); // subtraction
  void operator*=(const Array &arr); // multiplication
  void operator/=(const Array &arr); // division

  Array operator+(const T &arr); // addition
  Array operator-(const T &arr); // subtraction
  Array operator*(const T &arr); // multiplication
  Array operator/(const T &arr); // division

  void operator+=(const T &arr); // addition
  void operator-=(const T &arr); // subtraction
  void operator*=(const T &arr); // multiplication
  void operator/=(const T &arr); // division

  void fill(T e);      // fill array with one element
  void insert(T e);    // add's element on start (not optimal)
  void push_back(T e); // add's element on end (not optimal)

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