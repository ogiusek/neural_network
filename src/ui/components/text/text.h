#ifndef TYPE_TEXT_H
#define TYPE_TEXT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

enum class Align
{
  START,
  CENTER,
  END
};

class TEXT
{
public:
  int x, y;
  int fontSize = 32;
  const char *text;
  SDL_Color color = {0, 0, 0};
  Align xAlign = Align::START;
  Align yAlign = Align::START;

  void Draw(SDL_Renderer *renderer);
  TEXT(int _x, int _y, const char *_text, int _fontSize = 32);
};

#endif