#include "Brick.h"

Brick::Brick(int x, int y, int width, int height, int health) :
    position(sf::Vector2f(x, y)), size(sf::Vector2f(width, height)), health(health)
{
    // Création de la forme rectangulaire représentant la brique
    shape = sf::RectangleShape(size);
    shape.setOutlineThickness(2);
    shape.setOutlineColor(sf::Color::Black);
    shape.setPosition(position);
    shape.setFillColor(getColorFromLife());
}

Brick::~Brick()
{
    // Rien à faire dans le destructeur
}

void Brick::draw(sf::RenderWindow& window)
{
    // Dessine la brique si celle-ci est "en vie"
    if (isAlive()) {
        window.draw(shape);
    }
}

sf::Color Brick::getColorFromLife()
{
    // Renvoie la couleur de la brique en fonction de son état de santé
    switch (health) {
    case 1:
        return sf::Color::Red;
    case 2:
        return sf::Color::Yellow;
    case 3:
        return sf::Color::Green;
    default:
        return sf::Color::White;
    }
}

bool Brick::isAlive()
{
    // Renvoie true si health est supérieur à 0, false sinon
    return health > 0;
}

void Brick::destroy(std::vector<Brick>& bricks)
{
    // Remove the brick from the vector of bricks
    bricks.erase(std::remove(bricks.begin(), bricks.end(), *this), bricks.end());
}

sf::RectangleShape Brick::getShape()
{
    return shape;
}

void Brick::hit()
{
    // Methode a appeler lorsque la brique est touchée
    // Decremente l'attribut health de 1
    health--;
    shape.setFillColor(getColorFromLife());
}

sf::Vector2f Brick::getPosition()
{
    // Accesseur de l'attribut position
    return position;
}

sf::Vector2f Brick::getSize()
{
    // Accesseur de l'attribut size
    return size;
}

bool Brick::operator==(const Brick& other) const
{
    return this == &other;
}
