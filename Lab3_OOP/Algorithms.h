#pragma once
#include "Polygon_plus.h"

vector<vector<Point>> GrahamAlgo(vector<Point> vect);
int polarCompare(Point p1, Point p2, Point origin);
void sortByPolar(vector<Point> vect, Point origin);

vector<vector<Point>> Keil_KirkpatrikAlgo(vector<Point> vect);


vector<vector<Point>> Andrew_JarwisAlgo(vector<Point> vect);
void sortByX(vector<Point> vect);


vector<vector<Point>> quickRecAlgo(vector<Point> vect);
