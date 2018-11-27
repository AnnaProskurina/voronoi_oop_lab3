#include "Algorithms.h"



Algorithms::Algorithms()
{
}

vector<Point> Algorithms::algo()
{
}


Algorithms::~Algorithms()
{
}

vector<Point> Graham::GrahamAlgo(vector<Point> vect)
{
	int temp = 0;
	for (int i = 0; i < vect.size(); i++)
	{
		if (vect[i] < vect[temp]) temp = i;
	}
	swap(vect[0], vect[temp]);
	Point origin = vect[0];
	sortByPolar(vect, origin);

	vector<Point> s;
	s.push_back(vect[0]);

	s.push_back(vect[1]);
	int j = s.size() - 1;
	for (int i = 2; i < vect.size(); i++)
	{
		while (s.size()>1 && vect[i].isLeft(s[j], s[j - 1]) == false)
		{
			if (s.size() > 1)
			{
				s.pop_back();
				j--;
			}
		}
		s.push_back(vect[i]);
		j++;
	}
	return s;
}

int Graham::polarCompare(Point p1, Point p2, Point origin)
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

void Graham::sortByPolar(vector<Point> vect, Point origin)
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

Graham::Graham()
{
	int i = 0;
	while (i < numOfPoints)
	{
		Point p;
		p.setX(double(abs(rand()% bordersOfScreen)));
		p.setY(double(abs(rand() % bordersOfScreen)));
		polygon.push_back(p);
	}
}

Graham::Graham(vector<Point> vec)
{
	copy(vec.begin(), vec.end(), polygon);
}

vector<Point> Graham::algo()
{
	return GrahamAlgo(polygon);
}

Keil_Kirkpatrik::Keil_Kirkpatrik()
{
	int i = 0;
	while (i < numOfPoints)
	{
		Point p;
		p.setX(double(abs(rand() % bordersOfScreen)));
		p.setY(double(abs(rand() % bordersOfScreen)));
		polygon.push_back(p);
	}
}

Keil_Kirkpatrik::Keil_Kirkpatrik(vector<Point> vec)
{
	copy(vec.begin(), vec.end(), polygon);
}

vector<Point> Keil_Kirkpatrik::algo()
{
	return Keil_KirkpatrikAlgo(polygon);
}
