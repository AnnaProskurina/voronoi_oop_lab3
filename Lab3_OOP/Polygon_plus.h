#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Point
{
private:
	double x, y;
public:
	Point();
	Point(double x_, double y_);
	Point operator+ (Point& other);
	Point operator- (Point& other);
	Point operator* (Point& other);
	friend ostream& operator << (ostream& stream, Point& point);

	double getX();
	double getY();
	void setX(double xNew);
	void setY(double yNew);

	 
	void changePoint();
};



class Line
{
private:
	Point point1, point2;
public:
	Line(Point& p1, Point& p2);
};

class Polygon
{
private:

public:
	~Polygon();
};

