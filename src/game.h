#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "Common.h"
#include "Map.h"

class Game {
 public:

  Game(std::size_t grid_width, std::size_t grid_height);

  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);

  int GetScore() const;
  int GetSize() const;

  Common::WindowType windowType = Common::WindowType::GameWindow;
 private:
  int gridWidth;
  int gridHeight;
  Snake snake;
  SDL_Point food;
  Map map;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood(Map &map);
  void Update(Map &map);
};

#endif