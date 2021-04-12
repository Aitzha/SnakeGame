//
// Created by габит айтжан on 4/11/21.
//

#ifndef SNAKEGAME_TEXT_H
#define SNAKEGAME_TEXT_H

#include <vector>
#include <string>
#include "SDL.h"

class Text {
public:
    class Line {
    public:
        Line(int a, int b) {this->a = a; this->b = b;};
        int a;
        int b;
    private:
    };

    Text()= default;;

    std::vector<std::vector<Text::Line>> identifyText(std::string sentence);
    std::vector<Text::Line> identifyLetter(char letter);
    SDL_Point getPoint(int a, int x, int y);
private:
};



#endif //SNAKEGAME_TEXT_H
