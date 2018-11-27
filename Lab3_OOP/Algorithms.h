#pragma once
#include "Polygon_plus.h"

class Algorithms
{
protected:
	int numOfPoints = 100;
	int bordersOfScreen = 600;
	vector<Point> polygon;
public:
	Algorithms();
	virtual ~Algorithms() = default;
	virtual vector<Point> algo();
};

class Graham :public Algorithms
{
private:
	vector<Point> GrahamAlgo(vector<Point> vect);
	int polarCompare(Point p1, Point p2, Point origin);
	void sortByPolar(vector<Point> vect, Point origin);
public:
	Graham();
	Graham(vector<Point> vec);
	vector<Point> algo();
};

class Keil_Kirkpatrik :public Algorithms
{
private:
	vector<Point> Keil_KirkpatrikAlgo(vector<Point> vect);
public:
	Keil_Kirkpatrik();
	Keil_Kirkpatrik(vector<Point> vec);
	vector<Point> algo();
};


