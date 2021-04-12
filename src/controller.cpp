#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}

void Controller::HandleInput(bool &running, Snake &snake,Common::WindowType &windowType,
                             Common &indicator, bool &superFoodExist, int &timer) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
      if(e.type == SDL_QUIT) {
          indicator.terminated = true;
      } else if(e.type == SDL_KEYDOWN && windowType == Common::WindowType::GameWindow) {
          if(e.key.keysym.sym == SDLK_w || e.key.keysym.sym == SDLK_UP) {
              ChangeDirection(snake, Snake::Direction::kUp,
                              Snake::Direction::kDown);
              break;
          } else if(e.key.keysym.sym == SDLK_s || e.key.keysym.sym == SDLK_DOWN) {
              ChangeDirection(snake, Snake::Direction::kDown,
                              Snake::Direction::kUp);
              break;
          } else if(e.key.keysym.sym == SDLK_a || e.key.keysym.sym == SDLK_LEFT) {
              ChangeDirection(snake, Snake::Direction::kLeft,
                              Snake::Direction::kRight);
              break;
          } else if(e.key.keysym.sym == SDLK_d || e.key.keysym.sym == SDLK_RIGHT) {
              ChangeDirection(snake, Snake::Direction::kRight,
                              Snake::Direction::kLeft);
              break;
          }
      } else if(e.type == SDL_KEYDOWN && windowType == Common::WindowType::InstructionWindow) {
          if(e.key.keysym.sym == SDLK_SPACE) {
              running = false;
              windowType = Common::WindowType::GameWindow;
          }
      } else if(e.type == SDL_KEYDOWN && windowType == Common::WindowType::ResetWindow) {
          if(e.key.keysym.sym == SDLK_r) {
              windowType = Common::WindowType::GameWindow;
              snake.size = 1;
              snake.head_x = gridWidth / 2;
              snake.head_y = gridHeight / 2;
              snake.alive = true;
              snake.body.clear();
              snake.direction = Snake::Direction::kUp;
              snake.speed = 0.1f;
              indicator.score = 0;
              indicator.count = 0;
              superFoodExist = false;
              timer = 0;
          }
      }
  }
}