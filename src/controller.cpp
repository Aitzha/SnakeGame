#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"
//#include "game.h"
using namespace std;

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}

void Controller::HandleInput(bool &running, Snake &snake, Common::WindowType &windowType) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
      if(e.type == SDL_QUIT) {
          running = false;
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
              windowType = Game::WindowType::gameWindow
          }
      } else if(e.type == SDL_KEYDOWN && windowType == Game::WindowType::resetWindow) {
          if(e.key.keysym.sym == SDLK_r) {
              running = false;
          }
      }
  }
}