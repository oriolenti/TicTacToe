#pragma once

#define MAPSIZE 3

struct Mapa {

    char map[MAPSIZE][MAPSIZE]{
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
        };

    void PrintMap();

};
Mapa m;