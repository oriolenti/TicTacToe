#include "map.h"
#include <stdlib.h>
#include <iostream>


void Mapa::PrintMap() {
    system("CLS");
    std::cout << std::endl;
    std::cout << " -------------- 3 EN RAYA --------------------" << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < MAPSIZE; i++) {
        if (i == 0) {
            std::cout << "               " << i << "  ";
        }
        else {
            std::cout << "   " << i << "  ";
        }
    }
    std::cout << std::endl;

    for (int j = 0; j < MAPSIZE; j++) {
        if (j == 0) {
            std::cout << "            -------";
        }
        else {
            std::cout << "------";
        }
    }
    std::cout << std::endl;

    for (int i = 0; i < MAPSIZE; i++) {


        std::cout << "          " << i << "";

        for (int j = 0; j < MAPSIZE + 1; j++) {
            char value = ' ';
            std::cout << " | " << value << "  ";
        }
        std::cout << std::endl;

        for (int j = 0; j < MAPSIZE; j++) {
            if (j == 0) {
                std::cout << "            -------";
            }
            else {
                std::cout << "------";
            }
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << " ---------------------------------------------" << std::endl;
    std::cout << std::endl;
}