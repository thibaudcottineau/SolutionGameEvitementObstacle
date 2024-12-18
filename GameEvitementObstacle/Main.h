#pragma once
#include "Header.h"
#include "Fonction.h"
#include "Player.h"
#include "Obstacle.h"

//fenetre
int width{ 800 };
int length{ 600 };
string nameAppli{ "Jeu eviter les obstacles" };
sf::ContextSettings settings{ 24 };
sf::RenderWindow window{ sf::VideoMode(width, length),  nameAppli, sf::Style::Default, settings };
sf::Event event;
//player
Player player{ Player(width, length) };
MovePlayer movePlayer{ MovePlayer{false,false,false,false} };
//Obstacles
vector<Obstacle> listeObstacle;
//textes
sf::Font font;
sf::Text text_vie;
sf::Text text_scor;
sf::Text text_gameOver;
sf::Text text_resultat;
//game
float score{ 0 };



