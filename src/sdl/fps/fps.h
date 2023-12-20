#include <SDL2/SDL.h>
#include <vector>

class Fps
{
private:
  int frame_limit = 0;
  int last_frame = 0;

  std::vector<int> last_frames;

  void PerformFrame();
  void CountFps();

public:
  int deltaTime = 0;
  int getFps();

  void MakeNewFrame();

  Fps(int _limit);
};
