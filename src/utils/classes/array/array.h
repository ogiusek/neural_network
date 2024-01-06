#ifndef TYPE_ARRAY
#define TYPE_ARRAY

template <typename T>
struct Array
{
  T *data = nullptr; // array
  int size = 0;      // array size

  T &operator[](int index); // returns element in array

  Array &operator=(const Array &arr); // assignment
  Array(const Array<T> &arr);         // copy initializer

  Array();                             // default
  explicit Array(int _size);           // allocate memory
  Array(T *arr);                       // array parse
  Array(T *arr, int _size);            // array parse
  Array(std::initializer_list<T> arr); // list initializer

  ~Array();
};

#endif