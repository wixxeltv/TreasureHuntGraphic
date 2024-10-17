#include <iostream>
#include <map>
#include "Map.h"

int main()
{
    Map map1;

    //Window
    sf::RenderWindow window(sf::VideoMode(800, 800), "Treasure Hunt", sf::Style::Titlebar | sf::Style::Close);
    sf::RectangleShape rect(sf::Vector2f(10, 10));

    //Text
    sf::Font font;
    if(!font.loadFromFile("fonts/Roboto-Black.ttf")){std::cout << "error font\n";}
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);

    //Background
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    if (!backgroundTexture.loadFromFile("sprites/island.png")) {
        std::cout << "Error loading background texture\n";
    }
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(static_cast<float>(window.getSize().x) / backgroundTexture.getSize().x,static_cast<float>(window.getSize().y) / backgroundTexture.getSize().y);

   
    rect.setFillColor(sf::Color::Red);
    bool hasWon = false;
    
    while (window.isOpen())
    {
        bool isPlaying = map1.checkLoose();
 
        window.clear();
        window.draw(backgroundSprite);
        if (!hasWon)
        {
            isPlaying ? text.setString("You loose poin poin poin... ") : text.setString("Wrong tries allowed : " + std::to_string(map1.getWrongTriesAllowed()));
        }
        else
        {
            text.setString("GG you win!!!!!!");
        }
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if(!isPlaying && !hasWon){
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == sf::Mouse::Left) 
                    { 
                        int x = event.mouseButton.x;
                        int y = event.mouseButton.y;
                        hasWon = map1.spriteTouched(x, y);
                    }
                }
            }
        }
       
        window.draw(text);
        map1.showMap(window);
        window.display();
    }

    return 0;
}
