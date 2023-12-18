#include "./fps.h"

void Fps::PerformFrame()
{
  // delay
  int wanted_time_between_frames = ceil(1000.0 / (float)limit);
  int time_between_frames = SDL_GetTicks() - last_frame;
  if (time_between_frames < wanted_time_between_frames)
    SDL_Delay(wanted_time_between_frames - time_between_frames);

  // update
  deltaTime = SDL_GetTicks() - last_frame;
  last_frame = SDL_GetTicks();
}

void Fps::CountFps()
{
  frameRate += 1;
  std::thread fps_thread([this]
                         {SDL_Delay(1000); frameRate -= 1; });
  fps_thread.detach();
}

void Fps::MakeNewFrame()
{
  PerformFrame();
  CountFps();
}

Fps::Fps(int _limit) : limit(_limit), last_frame(SDL_GetTicks()) {}