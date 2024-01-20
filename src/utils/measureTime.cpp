#include <functional>
#include <chrono>
#include <map>
#include <string>

namespace Utils
{
  namespace Time
  {
    // returns time in nanoseconds
    int measureTime(std::function<void()> func)
    {
      auto start = std::chrono::high_resolution_clock::now();
      func();
      auto end = std::chrono::high_resolution_clock::now();
      return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    }

    std::map<std::string, std::chrono::high_resolution_clock::time_point> timeMeasurements;

    void start(std::string name) { timeMeasurements[name] = std::chrono::high_resolution_clock::now(); }

    // returns time in nanoseconds
    size_t stop(std::string name) { return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - timeMeasurements[name]).count(); }
  };
};