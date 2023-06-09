#pragma once
#include <SFML/Graphics.hpp>
class Brick
{
private:
	sf::RectangleShape shape;
	sf::Vector2f position;
	sf::Vector2f size;
	int health;
public:
	Brick(int x, int y, int width, int height, int health);
	~Brick();
	void draw(sf::RenderWindow& window);
	sf::Color getColorFromLife();
	bool isAlive();
	void hit();
	sf::Vector2f getPosition();
	sf::Vector2f getSize();
	sf::RectangleShape getShape();
	void destroy(std::vector<Brick>& bricks);
	bool operator==(const Brick& other) const;
};
