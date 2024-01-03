#ifndef TYPE_ARRAY
#define TYPE_ARRAY

#include <vector>
#include <cstring>

template <typename T>
struct Array
{
  T *data = nullptr;                    // array
  int size;                             // array size
  T &operator[](int index);             // returns element in array
  Array &operator=(const Array &other); // assignment
  T *&operator()();                     // returns array

  template <typename... Args>
  Array(Args... arr);
  Array(T *arr);             // array parse
  Array(T *arr, int _size);  // array parse
  Array(std::vector<T> arr); // vector parse
  Array(int _size);          // allocate memory
  Array();                   // default

  ~Array();
};

#endif