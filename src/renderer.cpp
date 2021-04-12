#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::RenderText(Common::WindowType &windowType) {
    // Clear screen
    SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(sdl_renderer);

    // Draw text
    int x = 50, y = 50;
    Text text;
    std::vector<std::string> textToPrint;

    //choose text
    if(windowType == Common::WindowType::InstructionWindow) {
        textToPrint = instructionText;
    } else if(windowType == Common::WindowType::ResetWindow) {
        textToPrint = resetText;
    }

    //loop to draw each sentence
    for(auto sentence : textToPrint) {
        textTexture = text.identifyText(sentence);
        int wordStartIndex = 1;
        int wordEndIndex = 0;

        //loop to find word
        for(std::vector<Text::Line> element : textTexture) {
            wordEndIndex++;
            int space = 0;

            if(element.empty() || wordEndIndex == sentence.length()) {

                if(wordEndIndex == sentence.length()) {
                    space = 0;
                }

                if(((wordEndIndex - wordStartIndex - space) * 30) + x + 50 > screen_width) {
                    y += 50;
                    x = 50;
                }

                int currentIndex = 1;

                //loop to draw each letter of word
                for(auto letter : textTexture) {

                    if(currentIndex >= wordStartIndex) {

                        //loop to draw each line of letter
                        for(auto line : letter) {
                            SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
                            SDL_Point a = text.getPoint(line.a, x, y);
                            SDL_Point b = text.getPoint(line.b, x, y);
                            SDL_RenderDrawLine(sdl_renderer, a.x, a.y, b.x, b.y);
                        }

                        x += 30;

                        if(wordEndIndex == currentIndex) {
                            wordStartIndex = wordEndIndex + 1;
                            break;
                        }
                    }

                    currentIndex++;
                }
            }
        }

        y += 100;
        x = 50;
    }

    // Update Screen
    SDL_RenderPresent(sdl_renderer);
}

void Renderer::Render(Snake const snake, SDL_Point const &food, Map &map,
                      SDL_Point const &superFood, bool superFoodExist) {
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Render walls
  SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0xFF, 0x00, 0xFF);
  for(int i = 0; i < map.numberOfWallPoints; i++) {
      block.x = map.get_xPosOf(i) * block.w;
      block.y = map.get_yPosOf(i) * block.h;
      SDL_RenderFillRect(sdl_renderer, &block);
  }

  // Render food
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
  block.x = food.x * block.w;
  block.y = food.y * block.h;
  SDL_RenderFillRect(sdl_renderer, &block);

  // Render superFood
  if(superFoodExist) {
      SDL_SetRenderDrawColor(sdl_renderer, 0xDC, 0x14, 0x3C, 0xFF);
      block.x = superFood.x * block.w;
      block.y = superFood.y * block.h;
      SDL_RenderFillRect(sdl_renderer, &block);
  }

  // Render snake's body
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  for (SDL_Point const &point : snake.body) {
    block.x = point.x * block.w;
    block.y = point.y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
  }

  // Render snake's head
  block.x = static_cast<int>(snake.head_x) * block.w;
  block.y = static_cast<int>(snake.head_y) * block.h;
  if (snake.alive) {
    SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
  } else {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
  }
  SDL_RenderFillRect(sdl_renderer, &block);

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(Common indicator, int fps, int timer) {
  if(timer <= 0) {
      std::string title{"Snake Score: " + std::to_string(indicator.score) + " FPS: " + std::to_string(fps)};
      SDL_SetWindowTitle(sdl_window, title.c_str());
  } else {
      std::string title{"SuperFood will disappear in " + std::to_string(timer) + " sec"};
      SDL_SetWindowTitle(sdl_window, title.c_str());
  }
}
