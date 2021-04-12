#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <string>
#include "SDL.h"
#include "snake.h"
#include "Map.h"
#include "Common.h"
#include "Text.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void renderInstruction();
  void Render(Snake const snake, SDL_Point const &food, Map &map,
              SDL_Point const &superFood, bool superFoodExist);

  void UpdateWindowTitle(Common indicator, int fps, int timer);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;

    std::vector<std::vector<Text::Line>> textTexture;

  std::string instructionText = "Use WASD or arrow keys to move";
  std::string resetText = "press R to reset";
};

#endif