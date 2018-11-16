#include "Polygon_plus.h"
//#include <SFML/Graphics.hpp>

using namespace std;



Polygon_plus::Polygon_plus()
{
}


Polygon_plus::~Polygon_plus()
{
}

Point::Point()
{
	/*
	sf::CircleShape p(1.f);
	p.setFillColor(sf::Color::White);
	p.setPosition(0.f, 0,f);
	*/
}

Point::Point(double x_, double y_)
{
	/*
	x = x_;
	y = y_;
	sf::CircleShape p(1.f);
	p.setFillColor(sf::Color::White);
	p.setPosition(x.f, y.f);
	*/
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

void Point::changePoint()
{
	/*
	sf::CircleShape p(2.f);
	p.setFillColor(sf::Color::Green);
	*/
}

ostream & operator<<(ostream & stream, Point & point)
{
	// 
	return stream;
}
