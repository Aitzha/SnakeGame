//
// Created by габит айтжан on 4/11/21.
//

#include "Text.h"

std::vector<std::vector<Text::Line>> Text::identifyText(std::string s) {
    std::vector<std::vector<Line>> textCoordinates;

    for(char c : s) {
        textCoordinates.push_back(identifyLetter(c));
    }
    return textCoordinates;
}

std::vector<Text::Line> Text::identifyLetter(char c) {
    if(c == 'A' || c == 'a') {
        Text::Line line1(7, 1);
        Text::Line line2(1, 3);
        Text::Line line3(3, 9);
        Text::Line line4(4, 6);
        return std::vector<Text::Line> {line1, line2, line3, line4};
    } else if(c == 'B' || c == 'b') {
        Text::Line line1(7, 1);
        Text::Line line2(1, 3);
        Text::Line line3(3, 9);
        Text::Line line4(4, 6);
        Text::Line line5(7, 9);
        return std::vector<Text::Line> {line1, line2, line3, line4, line5};
    } else if(c == 'C' || c == 'c') {
        Text::Line line1(1, 3);
        Text::Line line2(1, 7);
        Text::Line line3(7, 9);
        return std::vector<Text::Line> {line1, line2, line3};
    } else if(c == 'D' || c == 'd') {
        Text::Line line1(1, 3);
        Text::Line line2(1, 7);
        Text::Line line3(7, 9);
        Text::Line line4(3, 9);
        return std::vector<Text::Line> {line1, line2, line3, line4};
    } else if(c == 'E' || c == 'e') {
        Text::Line line1(1, 3);
        Text::Line line2(1, 7);
        Text::Line line3(7, 9);
        Text::Line line4(4, 6);
        return std::vector<Text::Line> {line1, line2, line3, line4};
    } else if(c == 'F' || c == 'f') {
        Text::Line line1(1, 3);
        Text::Line line2(1, 7);
        Text::Line line3(4, 6);
        return std::vector<Text::Line> {line1, line2, line3};
    } else if(c == 'G' || c == 'g') {
        Text::Line line1(1, 3);
        Text::Line line2(1, 7);
        Text::Line line3(7, 9);
        Text::Line line4(5, 9);
        Text::Line line5(6, 9);
        return std::vector<Text::Line> {line1, line2, line3, line4, line5};
    } else if(c == 'H' || c == 'h') {
        Text::Line line1(1, 7);
        Text::Line line2(4, 6);
        Text::Line line3(3, 9);
        return std::vector<Text::Line> {line1, line2, line3};
    } else if(c == 'I' || c == 'i') {
        Text::Line line1(1, 3);
        Text::Line line2(2, 8);
        Text::Line line3(7, 9);
        return std::vector<Text::Line> {line1, line2, line3};
    } else if(c == 'J' || c == 'j') {
        Text::Line line1(1, 3);
        Text::Line line2(2, 8);
        Text::Line line3(7, 8);
        return std::vector<Text::Line> {line1, line2, line3};
    } else if(c == 'K' || c == 'k') {
        Text::Line line1(1, 7);
        Text::Line line2(4, 3);
        Text::Line line3(4, 9);
        return std::vector<Text::Line> {line1, line2, line3};
    } else if(c == 'L' || c == 'l') {
        Text::Line line1(1, 7);
        Text::Line line2(7, 9);
        return std::vector<Text::Line> {line1, line2};
    } else if(c == 'M' || c == 'm') {
        Text::Line line1(1, 7);
        Text::Line line2(3, 9);
        Text::Line line3(1, 5);
        Text::Line line4(5, 3);
        return std::vector<Text::Line> {line1, line2, line3, line4};
    } else if(c == 'N' || c == 'n') {
        Text::Line line1(1, 7);
        Text::Line line2(3, 9);
        Text::Line line3(1, 9);
        return std::vector<Text::Line> {line1, line2, line3};
    } else if(c == 'O' || c == 'o') {
        Text::Line line1(1, 3);
        Text::Line line2(1, 7);
        Text::Line line3(7, 9);
        Text::Line line4(3, 9);
        return std::vector<Text::Line> {line1, line2, line3, line4};
    } else if(c == 'P' || c == 'p') {
        Text::Line line1(1, 3);
        Text::Line line2(1, 7);
        Text::Line line3(4, 6);
        Text::Line line4(6, 3);
        return std::vector<Text::Line> {line1, line2, line3, line4};
    } else if(c == 'Q' || c == 'q') {
        Text::Line line1(1, 3);
        Text::Line line2(1, 7);
        Text::Line line3(7, 9);
        Text::Line line4(3, 9);
        Text::Line line5(9, 10);
        return std::vector<Text::Line> {line1, line2, line3, line4, line5};
    } else if(c == 'R' || c == 'r') {
        Text::Line line1(1, 3);
        Text::Line line2(1, 7);
        Text::Line line3(4, 6);
        Text::Line line4(6, 3);
        Text::Line line5(4, 9);
        return std::vector<Text::Line> {line1, line2, line3, line4, line5};
    } else if(c == 'S' || c == 's') {
        Text::Line line1(1, 3);
        Text::Line line2(1, 4);
        Text::Line line3(4, 6);
        Text::Line line4(6, 9);
        Text::Line line5(7, 9);
        return std::vector<Text::Line> {line1, line2, line3, line4, line5};
    } else if(c == 'T' || c == 't') {
        Text::Line line1(1, 3);
        Text::Line line2(2, 8);
        return std::vector<Text::Line> {line1, line2};
    } else if(c == 'U' || c == 'u') {
        Text::Line line1(1, 7);
        Text::Line line2(7, 9);
        Text::Line line3(9, 3);
        return std::vector<Text::Line> {line1, line2, line3};
    } else if(c == 'V' || c == 'v') {
        Text::Line line1(1, 8);
        Text::Line line2(8, 3);
        return std::vector<Text::Line> {line1, line2};
    } else if(c == 'W' || c == 'w') {
        Text::Line line1(1, 7);
        Text::Line line2(3, 9);
        Text::Line line3(7, 5);
        Text::Line line4(5, 9);
        return std::vector<Text::Line> {line1, line2, line3, line4};
    } else if(c == 'X' || c == 'x') {
        Text::Line line1(1, 9);
        Text::Line line2(3, 7);
        return std::vector<Text::Line> {line1, line2};
    } else if(c == 'Y' || c == 'y') {
        Text::Line line1(1, 5);
        Text::Line line2(5, 3);
        Text::Line line3(5, 8);
        return std::vector<Text::Line> {line1, line2, line3};
    } else if(c == 'Z' || c == 'z') {
        Text::Line line1(1, 3);
        Text::Line line2(3, 7);
        Text::Line line3(7, 9);
        return std::vector<Text::Line> {line1, line2, line3};
    } else {
        return std::vector<Text::Line>();
    }
    ;
}

SDL_Point Text::getPoint(int a, int x, int y) {
    SDL_Point point;
    if(a == 1) {
        point.x = x;
        point.y = y;
    } else if(a == 2) {
        point.x = x + 10;
        point.y = y;
    } else if(a == 3) {
        point.x = x + 20;
        point.y = y;
    } else if(a == 4) {
        point.x = x;
        point.y = y + 20;
    } else if(a == 5) {
        point.x = x + 10;
        point.y = y + 20;
    } else if(a == 6) {
        point.x = x + 20;
        point.y = y + 20;
    } else if(a == 7) {
        point.x = x;
        point.y = y + 40;
    } else if(a == 8) {
        point.x = x + 10;
        point.y = y + 40;
    } else if(a == 9) {
        point.x = x + 20;
        point.y = y + 40;
    } else if(a == 10) {
        point.x = x + 25;
        point.y = y + 50;
    }
    return point;
}
