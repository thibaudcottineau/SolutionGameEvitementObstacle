#include "Player.h"

Player::Player(int& widthWindow, int& lengthWindow) : widthWindow(widthWindow), lengthWindow(lengthWindow)
{
	this->shape.setFillColor(this->color);
	this->shape.setOrigin(this->origin);
	this->shape.setPosition(this->positionDeparture);
}

void Player::drawPlayer(sf::RenderWindow& window) {
	window.draw(this->shape);
}

void Player::movePlayer(MovePlayer& movePlayer) {
	if (movePlayer.up == true && this->shape.getPosition().y > this->rayonne) { this->shape.move(0, -this->speed); }
	if (movePlayer.down == true && this->shape.getPosition().y < this->lengthWindow - this->rayonne) { this->shape.move(0, this->speed); }
	if (movePlayer.left == true && this->shape.getPosition().x > this->rayonne) { this->shape.move(-this->speed, 0); }
	if (movePlayer.right == true && this->shape.getPosition().x < this->widthWindow - this->rayonne) { this->shape.move(this->speed, 0); }
}

sf::CircleShape Player::get_shape() { return this->shape; }

int  Player::get_pv() { return this->pv; }
void  Player::losePV() { this->pv--; }