#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>
#include "snake.h"
#include "fruit.h"
#include "menu.h"


float menu(sf::RenderWindow &window, sf::Text text[], sf::RectangleShape &base, sf::RectangleShape &option, sf::RectangleShape &option2)
{
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type==sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Cyan);

        for(int i=0; i<1000; i+=100)
        {
            for (int j = 0; j < 1000; j += 100)
            {
                base.setPosition(i, j);
                window.draw(base);
            }
        }

        option.setPosition(30,500);
        window.draw(option);
        option2.setPosition(330,500);
        window.draw(option2);
        option.setPosition(730,500);
        window.draw(option);

        text[10].setString("EASY");
        text[10].setPosition(50,500);
        window.draw(text[10]);
        text[11].setString("NORMAL");
        text[11].setPosition(340,500);
        window.draw(text[11]);
        text[12].setString("HARD");
        text[12].setPosition(750,500);
        window.draw(text[12]);
        text[13].setString("SNAKE");
        text[13].setPosition(150, 100);
        text[13].setStyle(sf::Text::Italic);
        text[13].setCharacterSize(200);
        window.draw(text[13]);
        text[14].setString("Use 1,2,3 to set difficulty!");
        text[14].setFillColor(sf::Color::Yellow);
        text[14].setPosition(450,350);
        text[14].setCharacterSize(40);
        text[14].setRotation(340);
        window.draw(text[14]);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
        {
            return 0.3;
            break;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        {
            return 0.2;
            break;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
        {
            return 0.1;
            break;
        }

        window.display();
    }
    return 0;
}

void debug_display(sf::RenderWindow &window, sf::RectangleShape &fruit, sf::RectangleShape &base, sf::RectangleShape &edge, sf::RectangleShape &blocksnake, sf::RectangleShape &blocksnake2, sf::Text text[], Snake play[], int &size, Fruit &playfruit)
{
    for (int i = 0; i < 1000; i += 100) {
        for (int j = 0; j < 1000; j += 100) {
            if (j == 0 || j == 900 || i == 0 || i == 900) {
                edge.setPosition(i, j);
                window.draw(edge);
            } else {
                base.setPosition(i, j);
                window.draw(base);
            }
        }
    }
    text[1].setString("Score: ");
    std::string wynik = std::to_string(play[0].LengthOutput()-3);
    text[0].setString(wynik);
    text[0].setPosition(300, 0);
    window.draw(text[1]);
    window.draw(text[0]);

    for (int i = 0; i != play[0].LengthOutput(); i++) {
        blocksnake.setPosition(play[i].getX() * size, play[i].getY() * size);
        blocksnake2.setPosition(play[i].getX() * size, play[i].getY() * size);
        if (i == 0)
            window.draw(blocksnake2);
        else
            window.draw(blocksnake);
    }

    if ((play[0].getX() == playfruit.getX()) && (play[0].getY() == playfruit.getY())) {
        int D = 0;
        do {
            D = 0;
            playfruit.XYRandomize();
            for (int i = 0; i < play[0].LengthOutput(); i++) {
                if ((play[i].getX() != playfruit.getX() * size) && (play[i].getY() != playfruit.getY() * size))
                    D++;
            }
        } while (D != play[0].LengthOutput());

        fruit.setPosition(playfruit.getX() * size, playfruit.getY() * size);
        play[0].LengthADD();
    }
    window.draw(fruit);
}



void movement(Snake play[])
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        play[0].DirectionInput(0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        play[0].DirectionInput(1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        play[0].DirectionInput(2);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        play[0].DirectionInput(3);
    }
}

void Scoreboard(sf::RenderWindow &window, std::fstream &ofile, sf::Text text[], Snake play[])
{
    bool flag=false;
    bool flag2=false;

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type==sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);

        std::string wyniki;

        ofile.open("Scoreboard.txt", std::ios::in);
        if(ofile.good()==true && flag2==false)
        {
            for(int i=0; i<10; i++)
            {
                std::getline(ofile,wyniki);
                text[i+30].setString(wyniki);
                text[i+30].setPosition(i*100+10,900);
            }
            flag2=true;
        }
        ofile.close();

        text[40].setString("Last 10 scores:");
        text[40].setPosition(0,800);
        window.draw(text[40]);
        for(int i=0; i<10; i++)
        {
            window.draw(text[i+30]);
        }

        text[1].setString("Game over. Overall score:  ");
        std::string wynik = std::to_string(play[0].LengthOutput()-3);
        text[0].setString(wynik);
        text[0].setPosition(400,200);
        text[0].setCharacterSize(400);
        window.draw(text[1]);
        window.draw(text[0]);

        ofile.open ("Scoreboard.txt", std::ios::out | std::ios::app);
        if(ofile.good()==true && flag==false)
        {
            ofile << wynik;
            ofile << "\n";
            flag=true;
        }
        ofile.close();


        window.display();
    }
}

void SnakeMovement(Snake play[])
{
    for(int i = play[0].LengthOutput(); i!=0; i--)
    {
        play[i].x = play[i-1].x;
        play[i].y = play[i-1].y;
    }

    if(play[0].DirectionOutput() == 0)
    {
        play[0].y -= 1;
    }
    if(play[0].DirectionOutput() == 1)
    {
        play[0].x -= 1;
    }
    if(play[0].DirectionOutput() == 2)
    {
        play[0].y += 1;
    }
    if(play[0].DirectionOutput() == 3)
    {
        play[0].x += 1;
    }
}