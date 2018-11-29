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
	virtual vector<vector<Point>> algo();
};

class Graham :public Algorithms
{
private:
	vector<vector<Point>> GrahamAlgo(vector<Point> vect);
	int polarCompare(Point p1, Point p2, Point origin);
	void sortByPolar(vector<Point> vect, Point origin);
public:
	Graham();
	Graham(vector<Point> vec);
	vector<vector<Point>> algo();
};

class Keil_Kirkpatrik :public Algorithms
{
private:
	vector<vector<Point>> Keil_KirkpatrikAlgo(vector<Point> vect);
public:
	Keil_Kirkpatrik();
	Keil_Kirkpatrik(vector<Point> vec);
	vector<vector<Point>> algo();
};

class  Andrew_Jarwis:public Algorithms
{
private:
	vector<vector<Point>> Andrew_JarwisAlgo(vector<Point> vect);
	vector<Point> sortByX(vector<Point> vect);
public:
	Andrew_Jarwis();
	Andrew_Jarwis(vector<Point> vec);
	vector<vector<Point>> algo();
};


class  quickRec :public Algorithms
{
private:
	vector<vector<Point>> quickRecAlgo(vector<Point> vect);
	vector<Point> sortByX(vector<Point> vect);
public:
	quickRec();
	quickRec(vector<Point> vec);
	vector<vector<Point>> algo();
};