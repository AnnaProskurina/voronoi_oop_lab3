#include "Polygon_plus.h"
#include <SFML/Graphics.hpp>

using namespace std;


Point::Point()
{
	/*sf::CircleShape p(1.f);
	p.setFillColor(sf::Color::White);
	p.setPosition(0.f, 0.f);*/

	x = 0;
	y = 0;
}

Point::Point(double x_, double y_)
{
	x = x_;
	y = y_;
	/*sf::CircleShape p(1.f);
	p.setFillColor(sf::Color::White);
	p.setPosition(x, y);*/
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

bool Point::operator<(Point & other)
{
	if ((y < other.y) || (y == other.y && x < other.x)) return true;
	else
		return false;
}

bool Point::sortX(Point & other)
{
	if ((x < other.x) || (x == other.x && y < other.y)) return true;
	else
		return false;
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

double Point::moduleOfVect()
{
	return sqrt(x*x + y*y);
}

double Point::polarAngle()
{
	if (x == 0.0 && y == 0.0) return -1.0;
	if (x == 0.0 && y > 0.0) return 90.0;
	if (x == 0.0 && y <= 0.0) return 270.0;
	double phi = atan(y / x)*360./(2* 3, 14159265358979);

	if (x == 0.0 && y > 0.0) return phi;
	if (x == 0.0 && y <= 0.0) return phi + 360.;
	else
		return phi + 180.;
}

bool Point::isLeft(Point pBase, Point p1)
{
	Point p = *this;
	Point a = p1 - pBase;
	Point b = p - pBase;
	double sign = a.x*b.y - b.x*a.y;
	return sign >= 0.0;
}

bool Point::isRight(Point pBase, Point p1)
{
	Point p = *this;
	Point a = p1 - pBase;
	Point b = p - pBase;
	double sign = a.x*b.y - b.x*a.y;
	return sign <= 0.0;
}

bool Point::relateToLine(Point P1, Point P2)
{
	if ((x - P1.x) / (P2.x - P1.x) - (y - P1.y) / (P2.y - P1.y) >= 0) return true;
	else 
		return false;
}
