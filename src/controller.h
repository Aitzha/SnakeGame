#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include "Common.h"

class Controller {
 public:
  Controller(int gridWidth, int gridHeight) {
      this->gridWidth = gridWidth;
      this->gridHeight = gridHeight;
  }

  void HandleInput(bool &running, Snake &snake, Common::WindowType &windowType,
                   Common &indicator, bool &superFoodExist, int &timer) const;

 private:
  int gridWidth;
  int gridHeight;
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif