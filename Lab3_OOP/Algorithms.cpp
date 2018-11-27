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

vector<Point> Keil_Kirkpatrik::Keil_KirkpatrikAlgo(vector<Point> vect) //fix or rewrite
{
	vector<Point> LeftCoord, RightCoord, temporary;
	Point temp;
	for (int i = 1; i<vect.size() - 1; i++)
		if (vect[i - 1] < vect[i])
		{
			temp = vect[i];
			vect[i] = vect[i + 1];
			vect[i + 1] = temp;
		}

	int t = 1;
	LeftCoord.push_back(vect[t - 1]);
	while (vect[t - 1].getY() == vect[t].getY()) t++;
	RightCoord.push_back(vect[t - 1]);

	vector<Point> s;
	s.push_back(vect[0]);

	s.push_back(vect[1]);
	int j = s.size() - 1;
	for (int i = 2; i < LeftCoord.size(); i++)
	{
		while (s.size()>1 && LeftCoord[i].isRight(s[j], s[j - 1]) == false)
		{
			if (s.size() > 1)
			{
				s.pop_back();
				j--;
			}
		}
		s.push_back(LeftCoord[i]);
		j++;
	}

	for (int i = RightCoord.size(); i < 0; i--)
	{
		while (s.size()>1 && RightCoord[i].isLeft(s[j], s[j - 1]) == false)
		{
			if (s.size() > 1)
			{
				s.pop_back();
				j--;
			}
		}
		s.push_back(RightCoord[i]);
		j++;
	}

	return s;
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

vector<Point> Andrew_Jarwis::Andrew_JarwisAlgo(vector<Point> vect) //write code of left and right points + algo
{

}

Andrew_Jarwis::Andrew_Jarwis()
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

Andrew_Jarwis::Andrew_Jarwis(vector<Point> vec)
{
	copy(vec.begin(), vec.end(), polygon);
}

vector<Point> Andrew_Jarwis::algo()
{
	return Andrew_JarwisAlgo(polygon);
}