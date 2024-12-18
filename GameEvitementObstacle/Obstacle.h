#pragma once
#include "Header.h"

class Obstacle
{
public:
	//Constructeur
	Obstacle(float speed, float rayonne, sf::Vector2f positionDeparture);
	//Destructeur
	~Obstacle();
	//Methodes
	void drawObstacle(sf::RenderWindow& window);
	void moveObstacle();
	sf::CircleShape get_shape();
	void changePosition(sf::Vector2f position);

private:
	//Attributs
	float speed;
	float rayonne;
	sf::Vector2f positionDeparture;
	sf::Vector2f origin{ rayonne, rayonne };
	sf::Color color{ 255, 46, 0 };
	sf::CircleShape shape{ rayonne };
};


