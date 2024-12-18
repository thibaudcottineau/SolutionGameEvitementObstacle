#pragma once
#include "Header.h"
#include "Obstacle.h"

//fonction
void creat_listeObstacle(vector<Obstacle>& listeObstacle, int& windowWidth, int& windowHeight, int distance, int nbrObstacle, int rayonne);

bool is_colition2circle(sf::FloatRect&& player, sf::FloatRect&& obstacle);

void creatTexts(sf::Font& font, sf::Text& text_vie, int pv, sf::Text& text_scor, sf::Text& text_gameOver, sf::Text& text_resultat);
