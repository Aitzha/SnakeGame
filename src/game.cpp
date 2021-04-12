#include "game.h"
#include "controller.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)),
      gridWidth(grid_width), gridHeight(grid_height){
    map.setGridWidth(grid_width);
    map.setGridHeight(grid_height);
    map.makeMap();
}

void Game::showInstruction(Controller const &controller, Renderer &renderer,
                           std::size_t target_frame_duration) {
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;
    bool running = true;

    while(running && !indicator.terminated) {
        frame_start = SDL_GetTicks();

        controller.HandleInput(running, snake, windowType, indicator, superFoodExist, timerForSuperFood);
        renderer.renderInstruction();

        frame_end = SDL_GetTicks();
        frame_duration = frame_end - frame_start;

        if (frame_duration < target_frame_duration) {
            SDL_Delay(target_frame_duration - frame_duration);
        }
    }
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  PlaceFood();

  while (running && !indicator.terminated) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake, windowType, indicator, superFoodExist, timerForSuperFood);
    Update();
    renderer.Render(snake, food, map, superFood, superFoodExist);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;


    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(indicator, frame_count, timerForSuperFood);
      frame_count = 0;
      title_timestamp = frame_end;
      //keep track of timer for super food
      if(superFoodExist) {
          timerForSuperFood -= 1;
      }
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }

  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    int count = 0;
    bool notOnSnake = false;
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      notOnSnake = true;
    }

    //Check the the location is not occupied by the walls
    for(int i = 0; i < map.numberOfWallPoints; i++) {
        if(x != map.get_xPosOf(i) && y != map.get_yPosOf(i)) {
            count++;
        }
    }

    if(count == map.numberOfWallPoints && notOnSnake) {
        food.x = x;
        food.y = y;
        return;
    }
  }
}

void Game::Update() {
  if (!snake.alive) {
      windowType = Common::WindowType::ResetWindow;
      return;
  }

  snake.Update(map);

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if(food.x == new_x && food.y == new_y) {
    indicator.count++;
    indicator.score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.01;

    //check if 10 basic foods are collected
    if(indicator.count % 10 == 0) {
        superFoodExist = true;
        PlaceSuperFood();
        timerForSuperFood = 10;
    }
  }

  if(timerForSuperFood <= 0) {
      superFoodExist = false;
  } else if(superFoodExist && superFood.x == new_x && superFood.y == new_y) {
      timerForSuperFood = 0;
      superFoodExist = false;
      indicator.score += 5;
  }
}

int Game::GetSize() const { return snake.size; }

void Game::PlaceSuperFood() {
    int x, y;
    while (true) {
        x = random_w(engine);
        y = random_h(engine);
        int count = 0;
        bool notOnSnake = false;
        bool notOnFood = false;

        // Check that the location is not occupied by a snake item before placing
        // food.
        if (!snake.SnakeCell(x, y)) {
            notOnSnake = true;
        }

        //Check that the location is not occupied by the walls
        for(int i = 0; i < map.numberOfWallPoints; i++) {
            if(x != map.get_xPosOf(i) && y != map.get_yPosOf(i)) {
                count++;
            }
        }

        //Check that the location is not occupied by another food
        if(x != food.x && y != food.y) {
            notOnFood = true;
        }

        if(count == map.numberOfWallPoints && notOnSnake && notOnFood) {
            superFood.x = x;
            superFood.y = y;
            return;
        }
    }
}
