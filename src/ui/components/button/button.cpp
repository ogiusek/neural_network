#include "./button.h"

void Button::Update(Inputs &inputs)
{
  if (inputs.mousePresses(1) &&
      inputs.x > x && inputs.x < x + w &&
      inputs.y > y && inputs.y < y + h)
    action();
}

void Button::Draw(SDL_Renderer *renderer)
{
  SDL_Rect rect = {x, y, w, h};
  SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
  SDL_RenderFillRect(renderer, &rect);

  text.Draw(renderer);
}

Button::Button(int _x, int _y, int _w, int _h, std::function<void()> _action)
    : x(_x), y(_y), w(_w), h(_h), action(_action) {}