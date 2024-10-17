#pragma once
#include "SFML/Graphics.hpp"

class Cell
{
public:

    sf::Vector2<float> cords;
    enum class Case
    {
        Diged = 1,
        Treasure,
        Nothing,
        FoundTreasure
    };
    void setCase(Case newCase);
    sf::Sprite sprite;
    Case getCase(){return _case;}
private:
    Case _case;
    void createCell();
    void setImage(sf::Texture texture);
    Cell cell()
    {
        createCell();
    }

};
