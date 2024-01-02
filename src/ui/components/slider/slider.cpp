#include "./slider.h"

int Slider::getKnobX()
{
  int knobSize = getKnobSize();
  int knobMargin = knobSize / 9 * 2;
  return x + ((knobSize + knobMargin) / 2) + (w - (knobSize + knobMargin)) * value;
}
int Slider::getKnobY() { return y + h / 2; }
int Slider::getKnobSize() { return (int)((float)h * 0.9); }

float Slider::getValue() { return (max - min) * value + min; }
void Slider::setValue(float _value) { value = std::max(0.0f, std::min(1.0f, (_value - min) / (max - min))); }

void Slider::Draw(SDL_Renderer *renderer)
{
  // background
  SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
  SDL_Rect backgroundRect = {x, y, w, h};
  SDL_RenderFillRect(renderer, &backgroundRect);

  // knob
  int knobX = getKnobX();
  int knobY = getKnobY();
  int knobSize = getKnobSize();
  SDL_Rect knobRect = {knobX - knobSize / 2, knobY - knobSize / 2, knobSize, knobSize};
  SDL_SetRenderDrawColor(renderer, knobColor.r, knobColor.g, knobColor.b, knobColor.a);
  SDL_RenderFillRect(renderer, &knobRect);

  // value text
  float value = getValue();
  std::string valueText = std::to_string(value);
  size_t decimal_pos = valueText.find('.');
  if (decimal_pos != std::string::npos && decimal_pos + 3 < valueText.size())
    valueText.erase(decimal_pos + 3);

  TEXT text(knobX + 1 + knobSize / 2, knobY, valueText, h);
  text.yAlign = Align::CENTER;
  text.color = knobTextColor;
  text.Draw(renderer);

  // comment text
  comment.Draw(renderer);
}

void Slider::Update(Inputs &inputs)
{
  if (inputs.mousePresses(1) &&
      inputs.x > x && inputs.x < x + w &&
      inputs.y > y && inputs.y < y + h)
    isHeld = true;
  else if (!inputs.mouseHolds(1))
    isHeld = false;

  if (isHeld)
  {
    value = std::min(1.0f, (std::max((inputs.x - x) / (float)w, 0.0f)));
    *assign = getValue();
  }
  setValue(*assign);
}

Slider::Slider(float _min, float _max, int _x, int _y, float *_assign)
    : min(_min), max(_max),
      x(_x), y(_y),
      assign(_assign) {}