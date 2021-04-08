//
// Created by габит айтжан on 4/8/21.
//

#include "Map.h"

void Map::makeMap() {
    int vertical_walls_h = gridHeight / 4;
    int horizontal_walls_w = gridWidth / 4;
    int vertical_walls_thickness;
    int horizontal_walls_thickness;

    //make map symmetric
    if(gridWidth % 2 == 0) {
        vertical_walls_thickness = 2;
    } else {
        vertical_walls_thickness = 1;
    }

    if(gridHeight % 2 == 0) {
        horizontal_walls_thickness = 2;
    } else {
        horizontal_walls_thickness = 1;
    }

    //make vertical walls
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < vertical_walls_thickness; j++) {
            for(int k = 0; k < vertical_walls_h; k++) {
                wall_xPos.push_back((gridWidth / 2) - 1 + j);
                if(i == 0) {
                    wall_yPos.push_back(k);
                }else {
                    wall_yPos.push_back(gridHeight - 1 - k);
                }
                numberOfWallPoints++;
            }
        }
    }



    //make horizontal walls
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < horizontal_walls_thickness; j++) {
            for(int k = 0; k < horizontal_walls_w; k++) {
                wall_yPos.push_back((gridHeight / 2) - 1 + j);
                if(i == 0) {
                    wall_xPos.push_back(k);
                }else {
                    wall_xPos.push_back(gridWidth - 1 - k);
                }
                numberOfWallPoints++;
            }
        }
    }
}

int Map::get_xPosOf(int index) {
    return wall_xPos[index];
}

int Map::get_yPosOf(int index) {
    return wall_yPos[index];
}
