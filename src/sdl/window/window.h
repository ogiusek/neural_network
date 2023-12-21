#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include <string>

class Window
{
public:
  int width, height,
      &w = width, &h = height;

  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;

  Window(int _width, int _height, std::string title);
  ~Window();
};