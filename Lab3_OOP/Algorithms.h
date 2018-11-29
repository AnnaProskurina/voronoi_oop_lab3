#pragma once
#include "Polygon_plus.h"

vector<Point> GrahamAlgo(vector<Point> vect);
int polarCompare(Point p1, Point p2, Point origin);
void sortByPolar(vector<Point> vect, Point origin);

vector<Point> Keil_KirkpatrikAlgo(vector<Point> vect);


vector<Point> Andrew_JarwisAlgo(vector<Point> vect);
void sortByX(vector<Point> vect);


vector<Point> quickRecAlgo(vector<Point> vect);
