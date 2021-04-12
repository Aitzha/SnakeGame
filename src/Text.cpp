//
// Created by габит айтжан on 4/11/21.
//

#include "Text.h"

std::vector<std::vector<Text::Line>> Text::identifyText(std::string sentence) {
    std::vector<std::vector<Line>> textCoordinates;

    for(char c : sentence) {
        textCoordinates.push_back(identifyLetter(c));
    }
    return textCoordinates;
}

std::vector<Text::Line> Text::identifyLetter(char letter) {
    if(letter == 'A' || letter == 'a') {
        Text::Line line1(7, 1);
        Text::Line line2(1, 3);
        Text::Line line3(3, 9);
        Text::Line line4(4, 6);
        return std::vector<Text::Line> {line1, line2, line3, line4};
    } else if(letter == 'B' || letter == 'b') {
        Text::Line line1(7, 1);
        Text::Line line2(1, 3);
        Text::Line line3(3, 9);
        Text::Line line4(4, 6);
        Text::Line line5(7, 9);
        return std::vector<Text::Line> {line1, line2, line3, line4, line5};
    } else if(letter == 'C' || letter == 'c') {
        Text::Line line1(1, 3);
        Text::Line line2(1, 7);
        Text::Line line3(7, 9);
        return std::vector<Text::Line> {line1, line2, line3};
    } else if(letter == 'D' || letter == 'd') {
        Text::Line line1(1, 3);
        Text::Line line2(1, 7);
        Text::Line line3(7, 9);
        Text::Line line4(3, 9);
        return std::vector<Text::Line> {line1, line2, line3, line4};
    } else if(letter == 'E' || letter == 'e') {
        Text::Line line1(1, 3);
        Text::Line line2(1, 7);
        Text::Line line3(7, 9);
        Text::Line line4(4, 6);
        return std::vector<Text::Line> {line1, line2, line3, line4};
    } else if(letter == 'F' || letter == 'f') {
        Text::Line line1(1, 3);
        Text::Line line2(1, 7);
        Text::Line line3(4, 6);
        return std::vector<Text::Line> {line1, line2, line3};
    } else if(letter == 'G' || letter == 'g') {
        Text::Line line1(1, 3);
        Text::Line line2(1, 7);
        Text::Line line3(7, 9);
        Text::Line line4(5, 9);
        Text::Line line5(6, 9);
        return std::vector<Text::Line> {line1, line2, line3, line4, line5};
    } else if(letter == 'H' || letter == 'h') {
        Text::Line line1(1, 7);
        Text::Line line2(4, 6);
        Text::Line line3(3, 9);
        return std::vector<Text::Line> {line1, line2, line3};
    } else if(letter == 'I' || letter == 'i') {
        Text::Line line1(1, 3);
        Text::Line line2(2, 8);
        Text::Line line3(7, 9);
        return std::vector<Text::Line> {line1, line2, line3};
    } else if(letter == 'J' || letter == 'j') {
        Text::Line line1(1, 3);
        Text::Line line2(2, 8);
        Text::Line line3(7, 8);
        return std::vector<Text::Line> {line1, line2, line3};
    } else if(letter == 'K' || letter == 'k') {
        Text::Line line1(1, 7);
        Text::Line line2(4, 3);
        Text::Line line3(4, 9);
        return std::vector<Text::Line> {line1, line2, line3};
    } else if(letter == 'L' || letter == 'l') {
        Text::Line line1(1, 7);
        Text::Line line2(7, 9);
        return std::vector<Text::Line> {line1, line2};
    } else if(letter == 'M' || letter == 'm') {
        Text::Line line1(1, 7);
        Text::Line line2(3, 9);
        Text::Line line3(1, 5);
        Text::Line line4(5, 3);
        return std::vector<Text::Line> {line1, line2, line3, line4};
    } else if(letter == 'N' || letter == 'n') {
        Text::Line line1(1, 7);
        Text::Line line2(3, 9);
        Text::Line line3(1, 9);
        return std::vector<Text::Line> {line1, line2, line3};
    } else if(letter == 'O' || letter == 'o') {
        Text::Line line1(1, 3);
        Text::Line line2(1, 7);
        Text::Line line3(7, 9);
        Text::Line line4(3, 9);
        return std::vector<Text::Line> {line1, line2, line3, line4};
    } else if(letter == 'P' || letter == 'p') {
        Text::Line line1(1, 3);
        Text::Line line2(1, 7);
        Text::Line line3(4, 6);
        Text::Line line4(6, 3);
        return std::vector<Text::Line> {line1, line2, line3, line4};
    } else if(letter == 'Q' || letter == 'q') {
        Text::Line line1(1, 3);
        Text::Line line2(1, 7);
        Text::Line line3(7, 9);
        Text::Line line4(3, 9);
        Text::Line line5(9, 10);
        return std::vector<Text::Line> {line1, line2, line3, line4, line5};
    } else if(letter == 'R' || letter == 'r') {
        Text::Line line1(1, 3);
        Text::Line line2(1, 7);
        Text::Line line3(4, 6);
        Text::Line line4(6, 3);
        Text::Line line5(4, 9);
        return std::vector<Text::Line> {line1, line2, line3, line4, line5};
    } else if(letter == 'S' || letter == 's') {
        Text::Line line1(1, 3);
        Text::Line line2(1, 4);
        Text::Line line3(4, 6);
        Text::Line line4(6, 9);
        Text::Line line5(7, 9);
        return std::vector<Text::Line> {line1, line2, line3, line4, line5};
    } else if(letter == 'T' || letter == 't') {
        Text::Line line1(1, 3);
        Text::Line line2(2, 8);
        return std::vector<Text::Line> {line1, line2};
    } else if(letter == 'U' || letter == 'u') {
        Text::Line line1(1, 7);
        Text::Line line2(7, 9);
        Text::Line line3(9, 3);
        return std::vector<Text::Line> {line1, line2, line3};
    } else if(letter == 'V' || letter == 'v') {
        Text::Line line1(1, 8);
        Text::Line line2(8, 3);
        return std::vector<Text::Line> {line1, line2};
    } else if(letter == 'W' || letter == 'w') {
        Text::Line line1(1, 7);
        Text::Line line2(3, 9);
        Text::Line line3(7, 5);
        Text::Line line4(5, 9);
        return std::vector<Text::Line> {line1, line2, line3, line4};
    } else if(letter == 'X' || letter == 'x') {
        Text::Line line1(1, 9);
        Text::Line line2(3, 7);
        return std::vector<Text::Line> {line1, line2};
    } else if(letter == 'Y' || letter == 'y') {
        Text::Line line1(1, 5);
        Text::Line line2(5, 3);
        Text::Line line3(5, 8);
        return std::vector<Text::Line> {line1, line2, line3};
    } else if(letter == 'Z' || letter == 'z') {
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
