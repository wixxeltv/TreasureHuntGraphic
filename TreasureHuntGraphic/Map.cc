#include "Map.h"

#include <iostream>
#include <ostream>
#include <SFML/Graphics.hpp>
#include "Cell.h"

int Map::getArraySize()
{
    return arraySize;
}
int Map::getPlayerTries()
{
    return  _playerTries;
}

int Map::getWrongTriesAllowed()
{
    return _wrongTriesAllowed;
}

int Map::random()
{
    return rand() % arraySize;
}
bool Map::isNumber()
{
    if(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore();
        return true;
    }
    return false;
}
void Map::createMap()
{
    srand(time(NULL));
    for (int i = 0; i < arraySize; ++i)
    {
        for (int j = 0; j < arraySize; ++j)
        {
            Cell cell;
            cell.setCase(Cell::Case::Nothing);
            theMap[i][j] = cell;
            
        }
    }
    theMap[random()][random()].setCase(Cell::Case::Treasure);
}

void Map::showMap(sf::RenderWindow& window) 
{
    for(int i = 0; i < arraySize; i++)
    {
        for(int j = 0; j < arraySize; j++)
        {
            Cell& cell = theMap[i][j];
            sf::Texture texture;
            switch (cell.getCase())
            {
            case Cell::Case::Nothing:
                if (!texture.loadFromFile("sprites/dirt.png")){std::cout << "error dirt\n";} break;
            case Cell::Case::Diged:
                if (!texture.loadFromFile("sprites/hole.jpg")){std::cout << "error hole\n";} break;
            case Cell::Case::FoundTreasure:
                if (!texture.loadFromFile("sprites/treasure.png")){std::cout << "error treasure\n";} break;
            case Cell::Case::Treasure:
                if (!texture.loadFromFile("sprites/dirt.png")){std::cout << "error dirt\n";} break;
            }
            cell.sprite.setTexture(texture);
            cell.sprite.setScale(0.3f, 0.3f);
            
            cell.sprite.setPosition(50 + j * texture.getSize().x, 50 + i * texture.getSize().y);
            window.draw(cell.sprite);
        }
    }
}
bool Map::checkLoose()
{

    return _wrongTriesAllowed <= 0;
}
bool Map::spriteTouched(int x, int y)
{
    for (auto& element : theMap)
    {
        for (auto& cell : element)
        {

            sf::FloatRect spriteBounds = cell.sprite.getGlobalBounds();
            if (spriteBounds.contains(static_cast<float>(x), static_cast<float>(y))) {
                _playerTries++;
                if(cell.getCase() == Cell::Case::Treasure)
                {
                    cell.setCase(Cell::Case::FoundTreasure);
                    return true;
                }
                if(cell.getCase() != Cell::Case::Diged){_wrongTriesAllowed--;}

                cell.setCase(Cell::Case::Diged);
                return false;
            }
        }
    }
   return  false;
}


