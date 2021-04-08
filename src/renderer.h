#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <string>
#include "SDL.h"
#include "SDL_ttf.h"
#include "snake.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void ShowInstruction();
  void Render(Snake const snake, SDL_Point const &food);
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  TTF_Font *textFont = TTF_OpenFont("OpenSans-Regular.ttf", 24);
  SDL_Color textColor = {150, 205, 55};

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;

  const char *instructionText = "To move snake use WASD or arrow keys"
                                  "To start the game press 'Space'";

  std::string resetText = "To restart the game press 'R'";
  std::string settingText = "Speed up when eat food";
};

#endif