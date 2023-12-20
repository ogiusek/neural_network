#include "./fps.h"

void Fps::PerformFrame()
{
  // delay
  int wanted_time_between_frames = ceil(1000.0 / (float)frame_limit);
  int time_between_frames = SDL_GetTicks() - last_frame;
  if (time_between_frames < wanted_time_between_frames)
    SDL_Delay(wanted_time_between_frames - time_between_frames);

  // update
  deltaTime = SDL_GetTicks() - last_frame;
  last_frame = SDL_GetTicks();
}

void Fps::MakeNewFrame()
{
  PerformFrame();
  CountFps();
}

void Fps::CountFps()
{
  int tick = SDL_GetTicks();
  last_frames.push_back(tick);

  while (last_frames[0] + 1000 < tick)
    last_frames.erase(last_frames.begin());
}

int Fps::getFps()
{
  return last_frames.size();
}

Fps::Fps(int _frame_limit) : frame_limit(_frame_limit), last_frame(SDL_GetTicks()) {}