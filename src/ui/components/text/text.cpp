#include "./text.h"

void TEXT::Draw(SDL_Renderer *renderer)
{
  if (!defined)
    return;
  TTF_Font *font = TTF_OpenFont("assets/fonts/font.ttf", fontSize);
  if (font == NULL)
    throw "Cannot open font";

  SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), color);
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

  int xOffset = 0;
  if (xAlign == Align::CENTER)
    xOffset = surface->w / 2;
  else if (xAlign == Align::END)
    xOffset = surface->w;

  int yOffset = 0;
  if (yAlign == Align::CENTER)
    yOffset = surface->h / 2;
  else if (yAlign == Align::END)
    yOffset = surface->h;

  SDL_Rect destRect = {x - xOffset, y - yOffset, surface->w, surface->h};
  SDL_RenderCopy(renderer, texture, NULL, &destRect);

  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);
  TTF_CloseFont(font);
}

TEXT::TEXT(int _x, int _y, std::string _text, int _fontSize)
    : x(_x), y(_y), text(_text), fontSize(_fontSize), defined(true)
{
}

TEXT::TEXT() {}