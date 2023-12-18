#include <SDL2/SDL.h>

#include <thread>

class Fps
{
private:
  int limit = 0;
  int last_frame = 0;

  void PerformFrame();
  void CountFps();

public:
  int deltaTime = 0;
  int &ticks = last_frame;
  int frameRate = 0;

  void MakeNewFrame();

  Fps(int _limit);
};
