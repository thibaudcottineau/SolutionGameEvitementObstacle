#pragma once
#include "Header.h"

class Player
{
public:
	//Constructeur
	Player(int& widthWindow, int& lengthWindow);
	//Methodes
	void drawPlayer(sf::RenderWindow& window);
	void movePlayer(MovePlayer& movePlayer);
	sf::CircleShape get_shape();
	int get_pv();
	void losePV();

private:
	//Attributs
	int pv{ 3 };
	int widthWindow;
	int lengthWindow;
	float speed{ 5 };
	float rayonne{ 20 };
	sf::Vector2f positionDeparture{ 400, 400 };
	sf::Vector2f origin{ rayonne, rayonne };
	sf::Color color{ 0, 162, 255 };
	sf::CircleShape shape{ rayonne };
};



