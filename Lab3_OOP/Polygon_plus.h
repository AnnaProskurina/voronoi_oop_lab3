#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <stack>

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
	bool operator< (Point& other);


	double getX();
	double getY();
	void setX(double xNew);
	void setY(double yNew);
	double moduleOfVect();	 
	void changePoint();
	double polarAngle();
	bool isLeft(Point pBase, Point p1);
	bool isRight(Point pBase, Point p1);

};


vector<Point> Graham(vector<Point> vect);
int polarCompare(Point p1, Point p2, Point origin);
void sortByPolar(vector<Point> vect, Point origin);


vector<Point> Keil_Kirkpatrick(vector<Point> vect);
