#include "Cell.h"
#include "SFML/Graphics.hpp"

void Cell::setCase(Case newCase)
{
    _case = newCase;
}
void Cell::setImage(sf::Texture texture)
{
    sprite.setTexture(texture);
    sprite.setScale(10, 10);
}

