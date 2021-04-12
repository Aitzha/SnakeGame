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

  int GetSize() const;

  Common::WindowType windowType = Common::WindowType::InstructionWindow;
  Common indicator;

  bool superFoodExist = false;
 private:
  int gridWidth;
  int gridHeight;

  Snake snake;
  Map map;

  SDL_Point food;
  SDL_Point superFood;
  int timerForSuperFood = 0;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  void PlaceFood();
  void PlaceSuperFood();
  void Update();
};

#endif