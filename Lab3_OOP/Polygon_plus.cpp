#include "Polygon_plus.h"
#include <SFML/Graphics.hpp>

using namespace std;


Point::Point()
{
	sf::CircleShape p(1.f);
	p.setFillColor(sf::Color::White);
	p.setPosition(0.f, 0.f);
}

Point::Point(double x_, double y_)
{
	x = x_;
	y = y_;
	sf::CircleShape p(1.f);
	p.setFillColor(sf::Color::White);
	p.setPosition(x, y);
}

Point Point::operator+(Point & other)
{
	Point res;
	res.x = x + other.x;
	res.y = y + other.y;
	return res;
}

Point Point::operator-(Point & other)
{
	Point res;
	res.x = x - other.x;
	res.y = y - other.y;
	return res;
}

Point Point::operator*(Point & other)
{
	Point res;
	res.x = x * other.x;
	res.y = y * other.y;
	return res;
}

double Point::getX()
{
	return x;
}

double Point::getY()
{
	return y;
}

void Point::setX(double xNew)
{
	x = xNew;
}

void Point::setY(double yNew)
{
	y = yNew;
}

void Point::changePoint()
{
	sf::CircleShape p(2.f);
	p.setFillColor(sf::Color::Green);
}

ostream & operator<<(ostream & stream, Point & point)
{
	// ???
	return stream;
}

Line::Line(Point & p1, Point & p2)
{
	point1.setX(p1.getX());
	point1.setY(p1.getY());
	point2.setX(p1.getX());
	point2.setY(p1.getY());


	/*
	sf::Vertex line[] =
	{
	sf::Vertex(sf::Vector2f(point1.getX().f, point1.getY().f)),
	sf::Vertex(sf::Vector2f(point2.getX().f, point2.getY().f)),
	};
	*/
}
