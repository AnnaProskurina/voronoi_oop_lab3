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
	bool operator< (Point& other); //sorted by Y coordinate

	bool sortX(Point& other);


	double getX();
	double getY();
	void setX(double xNew);
	void setY(double yNew);
	double moduleOfVect();	 
	double polarAngle();
	bool isLeft(Point pBase, Point p1);
	bool isRight(Point pBase, Point p1);
	bool relateToLine(Point P1, Point P2);
};