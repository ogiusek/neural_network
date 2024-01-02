#ifndef TYPE_SLIDER_H
#define TYPE_SLIDER_H

#include <SDL2/SDL.h>
#include <algorithm>
#include <string>

#include "../text/text.h"         // import text class
#include "../../../sdl/include.h" // import input class

class Slider
{
private:
  float min, max, value = 0.5;

  int getKnobX();
  int getKnobY();
  int getKnobSize();

public:
  int w = 300, h = 20,
      x, y;
  float *assign;
  TEXT comment;
  SDL_Color knobTextColor = {0, 0, 0, 255};
  SDL_Color knobColor = {128, 128, 128, 255};
  SDL_Color bgColor = {255, 255, 255, 255};

  bool isHeld = false;

  float getValue();
  void setValue(float _value);

  void Draw(SDL_Renderer *renderer);

  void Update(Inputs &inputs);

  Slider(float _min, float _max, int _x, int _y, float *assign = nullptr);
};

#endif