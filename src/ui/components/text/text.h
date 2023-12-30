#ifndef TYPE_TEXT_H
#define TYPE_TEXT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <string>

enum class Align
{
  START,
  CENTER,
  END
};

class TEXT
{
private:
  bool defined = true;

public:
  int x, y;
  int fontSize = 32;
  std::string text;
  SDL_Color color = {0, 0, 0};
  Align xAlign = Align::START;
  Align yAlign = Align::START;

  void Draw(SDL_Renderer *renderer);
  TEXT(int _x, int _y, std::string _text, int _fontSize = 32);
  TEXT(std::string _text);
  TEXT();
};

#endif