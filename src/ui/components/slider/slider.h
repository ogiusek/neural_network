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
  int w, h,
      x, y;
  SDL_Color color;

  bool isHeld = false;

  double getValue();
  void setValue(double _value);

  void Draw(SDL_Renderer *renderer);

  void Update(Inputs &inputs);

  Slider(double _min, double _max, int _x, int _y, int _w, int _h, SDL_Color _color = {128, 128, 128, 255});
};

#endif