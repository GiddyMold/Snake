#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>
#include "snake.h"
#include "fruit.h"
#include "menu.h"

int main()
{
    Snake play[1000];
    Fruit playfruit;
    bool flag=false;
    float time1 = 0, diff;
    std::fstream ofile;
    srand(time(NULL));

    int size=50, width=1000, height=1000;
    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode(width,height), "Test");
    sf::RectangleShape base(sf::Vector2f(100,100));
    sf::RectangleShape edge(sf::Vector2f(100, 100));
    sf::RectangleShape blocksnake(sf::Vector2f(size,size));
    sf::RectangleShape blocksnake2(sf::Vector2f(size,size));
    sf::RectangleShape fruit(sf::Vector2f(size,size));
    sf::RectangleShape option(sf::Vector2f(250,100));
    sf::RectangleShape option2(sf::Vector2f(350,100));
    option.setFillColor(sf::Color(100,100,100));
    option2.setFillColor(sf::Color(100,100,100));

    sf::Font font;
    if (!font.loadFromFile("Minecraft.ttf")){window.close();}
    sf::Text text[100];

    for(int i=0; i<100; i++)
    {
        text[i].setFont(font);
        text[i].setCharacterSize(80);
        text[i].setFillColor(sf::Color(169,169,169));
    }

    sf::Texture Tbase;
    sf::Texture Tedge;
    sf::Texture Tsnake;
    sf::Texture Tfruit;
    sf::Texture Tsnake2;
    Tbase.loadFromFile("base.png");
    Tedge.loadFromFile("edge.png");
    Tsnake.loadFromFile("snake.png");
    Tfruit.loadFromFile("fruit.png");
    Tsnake2.loadFromFile("snake2.png");
    base.setTexture(&Tbase);
    edge.setTexture(&Tedge);
    blocksnake.setTexture(&Tsnake);
    blocksnake2.setTexture(&Tsnake2);
    fruit.setTexture(&Tfruit);

    playfruit.XYRandomize();
    fruit.setPosition(playfruit.getX()*size,playfruit.getY()*size);

    diff=menu(window, text, base, option, option2);

    while(window.isOpen()) {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        time1 += time;
        if (time1 > diff) {
            time1 = 0;
            SnakeMovement(play);
        }

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Cyan);

        movement(play);
        debug_display(window, fruit, base, edge, blocksnake, blocksnake2, text, play, size, playfruit);

        if (play[0].getX() > 17 || play[0].getX() < 2 || play[0].getY() > 17 || play[0].getY() < 2) break;
        for (int i = 1; i < play[0].LengthOutput(); i++)
        {
            if((play[0].getX() == play[i].getX()) && (play[0].getY() == play[i].getY()) && play[0].LengthOutput()>3) flag=true;
        }
        if(flag==true) break;

        window.display();
    }

    Scoreboard(window,ofile,text,play);
}
