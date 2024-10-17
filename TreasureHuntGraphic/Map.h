#pragma once
#include <array>
#include "Cell.h"
#include "SFML/Graphics.hpp"
const int arraySize = 3;

class Map
{
private:
    int _playerTries;
    int _wrongTriesAllowed;
    int random();
public:  std::array<std::array<Cell, arraySize>, arraySize> theMap;
public:
    int getArraySize();
    int getPlayerTries();
    int getWrongTriesAllowed();
    bool isNumber();
   

  
    void createMap();
    void showMap(sf::RenderWindow& window);
    bool checkLoose();
    bool spriteTouched(int x, int y);

    
    Map() : _wrongTriesAllowed(5), _playerTries(0)
    {
        createMap();
    }
};
