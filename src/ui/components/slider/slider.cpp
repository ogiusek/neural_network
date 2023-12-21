#include "./slider.h"

int Slider::getKnobX()
{
  int knobSize = getKnobSize();
  int knobMargin = knobSize / 9 * 2;
  return x + ((knobSize + knobMargin) / 2) + (w - (knobSize + knobMargin)) * value;
}
int Slider::getKnobY() { return y + h / 2; }
int Slider::getKnobSize() { return (int)((double)h * 0.9); }

double Slider::getValue() { return (max - min) * value + min; }
void Slider::setValue(double _value) { value = std::max(0.0, std::min(1.0, (_value - min) / (max - min))); }

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
  double value = getValue();
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

  // DrawText(renderer, knobX + 1 + knobSize / 2, knobY, valueText.c_str(), h, {0, 0, 0}, Align::START, Align::CENTER);
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
    value = std::min(1.0, (std::max((inputs.x - x) / (double)w, 0.0)));
    *assign = getValue();
  }
  setValue(*assign);
}

Slider::Slider(double _min, double _max, int _x, int _y, double *_assign)
    : min(_min), max(_max),
      x(_x), y(_y),
      assign(_assign) {}
// class Slider
// {
// private:
//   double min, max, value = 0.5;

//   int getKnobX()
//   {
//     int knobSize = getKnobSize();
//     int knobMargin = knobSize / 9 * 2;
//     return x + ((knobSize + knobMargin) / 2) + (w - (knobSize + knobMargin)) * value;
//   }
//   int getKnobY() { return y + h / 2; }
//   int getKnobSize() { return (int)((double)h * 0.9); }

// public:
//   int w, h,
//       x, y;
//   SDL_Color color;

//   bool isHeld = false;

//   double getValue() { return (max - min) * value + min; }
//   void setValue(double _value) { value = std::max(0.0, std::min(1.0, (_value - min) / (max - min))); }

//   void Draw(SDL_Renderer *renderer)
//   {
//     SDL_Color bgColor = {255, 255, 255, 255};
//     SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
//     SDL_Rect backgroundRect = {x, y, w, h};
//     SDL_RenderFillRect(renderer, &backgroundRect);
//     // knob
//     int knobX = getKnobX();
//     int knobY = getKnobY();
//     int knobSize = getKnobSize();
//     SDL_Color knobColor = color;
//     SDL_Rect knobRect = {knobX - knobSize / 2, knobY - knobSize / 2, knobSize, knobSize};
//     SDL_SetRenderDrawColor(renderer, knobColor.r, knobColor.g, knobColor.b, knobColor.a);
//     SDL_RenderFillRect(renderer, &knobRect);

//     // value
//     double value = getValue();
//     std::string valueText = std::to_string(value);
//     size_t decimal_pos = valueText.find('.');
//     if (decimal_pos != std::string::npos && decimal_pos + 3 < valueText.size())
//       valueText.erase(decimal_pos + 3);

//     TEXT text(knobX + 1 + knobSize / 2, knobY, valueText.c_str(), h);
//     text.yAlign = Align::CENTER;
//     text.Draw(renderer);

//     // DrawText(renderer, knobX + 1 + knobSize / 2, knobY, valueText.c_str(), h, {0, 0, 0}, Align::START, Align::CENTER);
//   }

//   void Update(Inputs &inputs)
//   {
//     if (inputs.mousePresses(1) &&
//         inputs.x > x && inputs.x < x + w &&
//         inputs.y > y && inputs.y < y + h)
//       isHeld = true;
//     else if (!inputs.mouseHolds(1))
//       isHeld = false;

//     if (isHeld)
//       value = std::min(1.0, (std::max((inputs.x - x) / (double)w, 0.0)));
//   }

//   Slider(double _min, double _max, int _x, int _y, int _w, int _h, SDL_Color _color = {128, 128, 128, 255})
//       : min(_min), max(_max),
//         x(_x), y(_y),
//         w(_w), h(_h),
//         color(_color) {}
// };
