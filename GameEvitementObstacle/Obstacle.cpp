#include "Obstacle.h"

Obstacle::Obstacle(float speed, float rayonne, sf::Vector2f positionDeparture) : 
	speed(speed), rayonne(rayonne), positionDeparture(positionDeparture)
{
	this->shape.setFillColor(this->color);
	this->shape.setOrigin(this->origin);
	this->shape.setPosition(this->positionDeparture);
}
Obstacle::~Obstacle() {}
void Obstacle::drawObstacle(sf::RenderWindow& window) {
	window.draw(this->shape);
}

void Obstacle::moveObstacle() {
	this->shape.move(0, this->speed); 
}

sf::CircleShape Obstacle::get_shape() { return this->shape; }

void  Obstacle::changePosition(sf::Vector2f position) { shape.setPosition(position); }
