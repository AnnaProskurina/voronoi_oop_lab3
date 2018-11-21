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

bool Point::operator<(Point & other)
{
	if ((y < other.y) || (y == other.y && x < other.x)) return true;
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

void Point::changePoint()
{
	sf::CircleShape p(2.f);
	p.setFillColor(sf::Color::Green);
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


void Graham(vector<Point> vect)
{
	int temp = 0;
	for (int i = 0; i < vect.size(); i++)
	{
		if (vect[i] < vect[temp]) temp = i;
	}
	swap(vect[0], vect[temp]);
	Point origin = vect[0];
	sort(vect, origin);
	
	vector<Point> s;
	s.push_back(vect[0]);
	s.push_back(vect[1]);
	for (int i = 1; i < vect.size();)
	{
		//while (vect[i]->isLeft(s.front()-1, s.front()))

	}

}

int polarCompare(Point p1, Point p2, Point origin)
{
	Point temp1 = p1 - origin;
	Point temp2 = p2 - origin;
	double polar1 = temp1.polarAngle();
	double polar2 = temp2.polarAngle();
	if (polar1 < polar2) return -1;
	if (polar1 > polar2) return 1;
	if (temp1.moduleOfVect() < temp2.moduleOfVect())
		return -1;
	if (temp1.moduleOfVect() > temp2.moduleOfVect())
		return 1;
	return 0;
}

void sort(vector<Point> vect, Point origin)
{
	Point temp;
	for (int i = 1; i<vect.size() - 1; i++)
		for (int j = 1; j < vect.size() - 1; j++)
		{
			if (polarCompare(vect[i], vect[j], origin) == 1)
			{
				temp = vect[i];
				vect[i] = vect[i + 1];
				vect[i + 1] = temp;
			}
		}
}

