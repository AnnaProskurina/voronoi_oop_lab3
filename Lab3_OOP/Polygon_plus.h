#pragma once
//#include <SFML/Graphics.hpp>
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
	 
	void changePoint();

};


class Polygon_plus
{
public:
	Polygon_plus();
	~Polygon_plus();
};

