#ifndef SNAKE_MENU_H
#define SNAKE_MENU_H

float menu(sf::RenderWindow &window, sf::Text text[], sf::RectangleShape &base, sf::RectangleShape &option, sf::RectangleShape &option2);
void debug_display(sf::RenderWindow &window, sf::RectangleShape &fruit, sf::RectangleShape &base, sf::RectangleShape &edge, sf::RectangleShape &blocksnake, sf::RectangleShape &blocksnake2, sf::Text text[], Snake play[], int &size, Fruit &playfruit);
void movement(Snake play[]);
void Scoreboard(sf::RenderWindow &window, std::fstream &ofile, sf::Text text[], Snake play[]);
void SnakeMovement(Snake play[]);

#endif //SNAKE_MENU_H
