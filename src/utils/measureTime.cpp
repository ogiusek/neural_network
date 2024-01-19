#include <functional>
#include <chrono>

namespace Utils
{
  // returns time in nanoseconds
  int measureTime(std::function<void()> func)
  {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
  }
};