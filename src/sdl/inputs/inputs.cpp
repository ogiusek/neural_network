#include "./inputs.h"

bool Inputs::keyboardHolds(uint key) { return keyboard_held_keys.count(key); }
bool Inputs::keyboardPresses(uint key) { return keyboard_pressed_keys.count(key); }
void Inputs::showKeyboard()
{
  for (auto e : keyboard_pressed_keys)
    std::cout << e << " ";
  if (!keyboard_pressed_keys.empty())
    std::cout << "\n";
}

bool Inputs::mouseHolds(uint btn) { return mouse_held_keys.count(btn); }
bool Inputs::mousePresses(uint btn) { return mouse_pressed_keys.count(btn); }
void Inputs::showMouse()
{
  for (auto e : mouse_pressed_keys)
    std::cout << e << " ";
  if (!mouse_pressed_keys.empty())
    std::cout << "\n";
}

void Inputs::setMousePos(int nX, int nY)
{
  lastX = x;
  lastY = y;
  x = nX;
  y = nY;
}

bool Inputs::loadInputs()
{
  keyboard_pressed_keys.clear();
  mouse_pressed_keys.clear();

  SDL_Event event;
  bool running = 1;

  while (SDL_PollEvent(&event))
  {
    if (event.type == SDL_QUIT)
    {
      running = 0;
      continue;
    }

    if (event.type == SDL_MOUSEMOTION)
    {
      int nX, nY;
      SDL_GetMouseState(&nX, &nY);
      setMousePos(nX, nY);
      continue;
    }

    int pressed_key = int(event.key.keysym.sym);

    if (event.type == SDL_KEYDOWN)
    {
      keyboard_pressed_keys.insert(pressed_key);
      keyboard_held_keys.insert(pressed_key);
      continue;
    }

    if (event.type == SDL_KEYUP)
    {
      keyboard_held_keys.erase(pressed_key);
      continue;
    }

    int pressed_btn = int(event.button.button);

    if (event.type == SDL_MOUSEWHEEL)
    {
      scroll = event.wheel.y;
      continue;
    }

    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
      mouse_pressed_keys.insert(pressed_btn);
      mouse_held_keys.insert(pressed_btn);
      continue;
    }

    if (event.type == SDL_MOUSEBUTTONUP)
    {
      mouse_held_keys.erase(pressed_btn);
      continue;
    }
  }

  return running;
}
