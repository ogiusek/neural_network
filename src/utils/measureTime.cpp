#include <functional>
#include <chrono>

// returns time in microseconds
int measureTime(std::function<void()> func)
{
  auto start = std::chrono::high_resolution_clock::now();
  func();
  auto end = std::chrono::high_resolution_clock::now();
  return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}