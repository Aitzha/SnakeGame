#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include "Common.h"
//#include "game.h"
using namespace std;

class Controller {
 public:
  void HandleInput(bool &running, Snake &snake, Common::WindowType windowType) const;

 private:
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif