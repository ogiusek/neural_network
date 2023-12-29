#ifndef TYPE_BUTTON_H
#define TYPE_BUTTON_H

#include <SDL2/SDL.h>
#include <functional>

#include "../text/text.h"         // import text class
#include "../../../sdl/include.h" // import input class

class Button
{
private:
  std::function<void()> action;

public:
  int w = 300, h = 20,
      x, y;

  TEXT text;
  SDL_Color bgColor = {0, 0, 0, 255};

  void Draw(SDL_Renderer *renderer);

  void Update(Inputs &inputs);

  Button(int _x, int _y, int _w, int _h, std::function<void()> _action);
};

#endif