//
// Created by габит айтжан on 4/8/21.
//

#ifndef SNAKEGAME_MAP_H
#define SNAKEGAME_MAP_H

#include <vector>

class Map {
public:
    Map() {}

    void makeMap();
    void setGridWidth(int gridWidth) {this->gridWidth = gridWidth;}
    void setGridHeight(int gridHeight) {this->gridHeight = gridHeight;}

    int get_xPosOf(int index);
    int get_yPosOf(int index);
    int numberOfWallPoints = 0;
private:
    int gridWidth;
    int gridHeight;
    std::vector <int> wall_xPos;
    std::vector <int> wall_yPos;
};


#endif //SNAKEGAME_MAP_H
