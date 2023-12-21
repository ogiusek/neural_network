#include "./window.h"

Window::Window(int _width, int _height, std::string title) : width(_width), height(_height)
{
  TTF_Init();

  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    throw "SDL could not initialize!";

  // Create a window
  window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
  if (window == NULL)
    throw "Window could not be created!";

  // Create a renderer
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == NULL)
    throw "Renderer could not be created!";
}

Window::~Window()
{
  TTF_Quit();
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}