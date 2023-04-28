#include "Player.h"

Player::Player(int y, int width, int height) : y(y) {
    position = sf::Vector2f(0, y);
    size = sf::Vector2f(width, height);
    shape.setPosition(position);
    shape.setSize(size);
    shape.setFillColor(sf::Color::Red);
}

Player::~Player() {}

void Player::draw(sf::RenderWindow& window) {
    position.x = sf::Mouse::getPosition(window).x - size.x / 2;
    shape.setPosition(position);
    window.draw(shape);
}



sf::Vector2f Player::getPosition() {
    return position;
}

sf::Vector2f Player::getSize() {
    return size;
}



/*
#include "Player.h"

Player::Player(int y, int width, int height)
{
    this->position.x = 0;
    this->position.y = (float)y;
    this->size.x = (float)width;
    this->size.y = (float)height;
    this->y = y;
    this->shape = sf::RectangleShape(this->size);
    this->shape.setFillColor(sf::Color::Red);
}

Player::~Player()
{

}

void Player::draw(sf::RenderWindow& window)
{
    // Positionne la plateforme (attribut shape) en fonction de l’abscisse de la souris dans la fenêtre
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    float newX = (float)mousePosition.x - (this->size.x / 2.0f);
    if (newX < 0) newX = 0;
    else if (newX + this->size.x > window.getSize().x) newX = window.getSize().x - this->size.x;
    this->position.x = newX;
    this->shape.setPosition(this->position);

    // Dessine la plateforme à l’écran
    window.draw(this->shape);
}

sf::Vector2f Player::getPosition()
{
	return sf::Vector2f();
}

sf::Vector2f Player::getSize()
{
	return sf::Vector2f();
}
*/