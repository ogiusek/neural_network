#ifndef TYPE_SLIDER_H
#define TYPE_SLIDER_H

#include <SDL2/SDL.h>
#include <algorithm>
#include <string>

class Slider
{
private:
  double min, max, value = 0.5;

  int getKnobX();
  int getKnobY();
  int getKnobSize();

public:
  int w = 100, h = 20,
      x, y;
  double *assign;
  TEXT comment;
  SDL_Color knobTextColor = {0, 0, 0, 255};
  SDL_Color knobColor = {128, 128, 128, 255};
  SDL_Color bgColor = {255, 255, 255, 255};

  bool isHeld = false;

  double getValue();
  void setValue(double _value);

  void Draw(SDL_Renderer *renderer);

  void Update(Inputs &inputs);

  Slider(double _min, double _max, int _x, int _y, double *assign = nullptr);
};

#endif