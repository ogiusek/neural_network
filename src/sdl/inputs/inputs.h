#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include <set>

class Inputs
{
private:
  std::set<uint>
      keyboard_pressed_keys,
      keyboard_held_keys,

      mouse_pressed_keys,
      mouse_held_keys;

  void setMousePos(int x, int y);

public:
  int x = 0, y = 0,
      lastX = 0, lastY = 0,
      scroll = 0;

  bool keyboardHolds(uint key);
  bool keyboardPresses(uint key);
  void showKeyboard();

  bool mouseHolds(uint btn);
  bool mousePresses(uint btn);
  void showMouse();

  bool loadInputs();
};