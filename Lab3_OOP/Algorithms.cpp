#include "Algorithms.h"
/*
int numOfPoints = 100;
int bordersOfScreen = 600;


//***********************************

vector<Point> GrahamAlgo(vector<Point> vect)
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
	vector<vector<Point>> toPrint;
	s.push_back(vect[0]);
	s.back().changePoint();
	toPrint.push_back(s);

	s.push_back(vect[1]);
	s.back().changePoint();
	toPrint.push_back(s);

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
		s.back().changePoint();
		toPrint.push_back(s);
		j++;
	}
	return s;
};

int polarCompare(Point p1, Point p2, Point origin)
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
};

void sortByPolar(vector<Point> vect, Point origin)
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
};

//***********************************

vector<Point> Andrew_JarwisAlgo(vector<Point> vect)
{
	sortByX(vect);

	Point left = vect.front();
	Point right = vect.back();

	vector<Point> upHull, downHull;
	upHull.push_back(left);
	downHull.push_back(left);


	for (int i = 1; i < vect.size()-1; i++)
	{
		if (vect[i].relateToLine(left, right) == true)
		{
			upHull.push_back(vect[i]);
			cout << "upHull" << vect[i].getX() << vect[i].getY() << endl;
		}
		else
		{
			downHull.push_back(vect[i]);
			cout << "downHull" << vect[i].getX() << vect[i].getY() << endl;
		}

	}
	downHull.push_back(right);

	vector<Point> s;
	vector<vector<Point>> toPrint;


	for (int i = 1; i < upHull.size() - 1; i++)
	{
		for (int j = 1; j < upHull.size() - 1; j++)
		{
			if (upHull[j - 1].relateToLine(upHull[i - 1], upHull[i]) == upHull[j].relateToLine(upHull[i - 1], upHull[i]))
				s.push_back(upHull[i]);
				s.back().changePoint();
				toPrint.push_back(s);

		}
	}

	for (int i = downHull.size(); i > 1; i--)
	{
		for (int j = downHull.size(); j > 1; j--)
		{
			if (upHull[j - 1].relateToLine(upHull[i - 1], upHull[i]) == upHull[j].relateToLine(upHull[i - 1], upHull[i]))
				s.push_back(downHull[i]);
				s.back().changePoint();
				toPrint.push_back(s);

		}
	}
	return s;
};

void sortByX(vector<Point> vect)
{
	Point temp;
	for (int i = 1; i<vect.size() - 1; i++)
		for (int j = 0; j < vect.size(); j++)
		{
			if (vect[i-1].sortX(vect[j]))
			{
				temp = vect[i];
				vect[i] = vect[i + 1];
				vect[i + 1] = temp;
			}
		}
};

//***********************************

bool sortByY(Point a, Point b)
{
	return a < b;
}

vector<Point> Keil_KirkpatrikAlgo(vector<Point> vect) //fix or rewrite
{
	{
		vector<Point> LeftCoord, RightCoord, temporary;
		Point temp;
		sort(vect.begin(), vect.end(), sortByY);
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
};

//***********************************

vector<Point> quickRecAlgo(vector<Point> vect)
{
	sortByX(vect);

	Point left = vect.front();
	Point right = vect.back();

	vector<Point> upHull, downHull;
	upHull.push_back(left);
	downHull.push_back(left);

	for (int i = 1; i < vect.size() - 1; i++)
	{
		if (vect[i].relateToLine(left, right) == true)
			upHull.push_back(vect[i]);
		else
			downHull.push_back(vect[i]);
	}
	downHull.push_back(right);

	vector<Point> s;
	vector<vector<Point>> toPrint;
	return s;
};
*/

Algorithms::Algorithms()
{
}

vector<vector<Point>> Algorithms::algo()
{
}

//***********************************

vector<vector<Point>> Graham::GrahamAlgo(vector<Point> vect)
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
	vector<vector<Point>> toPrint;
	s.push_back(vect[0]);
	s.back().changePoint();
	toPrint.push_back(s);

	s.push_back(vect[1]);
	s.back().changePoint();
	toPrint.push_back(s);

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
		s.back().changePoint();
		toPrint.push_back(s);
		j++;
	}
	return toPrint;
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
		p.setX(double(abs(rand() % bordersOfScreen)));
		p.setY(double(abs(rand() % bordersOfScreen)));
		polygon.push_back(p);
	}
}

Graham::Graham(vector<Point> vec)
{
	copy(vec.begin(), vec.end(), polygon);
}

vector<vector<Point>> Graham::algo()
{
	return GrahamAlgo(polygon);
}


//***********************************

vector<vector<Point>> Keil_Kirkpatrik::Keil_KirkpatrikAlgo(vector<Point> vect) //fix or rewrite
{
	vector<Point> LeftCoord, RightCoord;
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
	vector<vector<Point>> toPrint;

	for (int i = 0; i < LeftCoord.size(); i++)
	{

	}

	return toPrint;
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

vector<vector<Point>> Keil_Kirkpatrik::algo()
{
	return Keil_KirkpatrikAlgo(polygon);
}


//***********************************

vector<vector<Point>> Andrew_Jarwis::Andrew_JarwisAlgo(vector<Point> vect)
{
	sortByX(vect);

	Point left = vect.front();
	Point right = vect.back();

	vector<Point> upHull, downHull;
	upHull.push_back(left);
	downHull.push_back(left);

	for (int i = 1; i < vect.size() - 1; i++)
	{
		if (vect[i].relateToLine(left, right) == true)
			upHull.push_back(vect[i]);
		else
			downHull.push_back(vect[i]);
	}
	downHull.push_back(right);

	vector<Point> s;
	vector<vector<Point>> toPrint;


	for (int i = 1; i < upHull.size() - 1; i++)
	{
		for (int j = 1; j < upHull.size() - 1; j++)
		{
			if (upHull[j - 1].relateToLine(upHull[i - 1], upHull[i]) == upHull[j].relateToLine(upHull[i - 1], upHull[i]))
				s.push_back(upHull[i]);
			s.back().changePoint();
			toPrint.push_back(s);

		}
	}

	for (int i = downHull.size(); i > 1; i--)
	{
		for (int j = downHull.size(); j > 1; j--)
		{
			if (upHull[j - 1].relateToLine(upHull[i - 1], upHull[i]) == upHull[j].relateToLine(upHull[i - 1], upHull[i]))
				s.push_back(downHull[i]);
			s.back().changePoint();
			toPrint.push_back(s);

		}
	}
	return toPrint;
}

vector<Point> Andrew_Jarwis::sortByX(vector<Point> vect)
{
	Point temp;
	for (int i = 1; i<vect.size() - 1; i++)
		for (int j = 0; j < vect.size(); j++)
		{
			if (vect[i - 1].sortX(vect[j]))
			{
				temp = vect[i];
				vect[i] = vect[i + 1];
				vect[i + 1] = temp;
			}
		}

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

vector<vector<Point>> Andrew_Jarwis::algo()
{
	return Andrew_JarwisAlgo(polygon);
}

//***********************************

vector<vector<Point>> quickRec::quickRecAlgo(vector<Point> vect)
{
	sortByX(vect);

	Point left = vect.front();
	Point right = vect.back();

	vector<Point> upHull, downHull;
	upHull.push_back(left);
	downHull.push_back(left);

	for (int i = 1; i < vect.size() - 1; i++)
	{
		if (vect[i].relateToLine(left, right) == true)
			upHull.push_back(vect[i]);
		else
			downHull.push_back(vect[i]);
	}
	downHull.push_back(right);

	vector<vector<Point>> toPrint;

}

vector<Point> quickRec::sortByX(vector<Point> vect)
{
	Point temp;
	for (int i = 1; i<vect.size() - 1; i++)
		for (int j = 0; j < vect.size(); j++)
		{
			if (vect[i - 1].sortX(vect[j]))
			{
				temp = vect[i];
				vect[i] = vect[i + 1];
				vect[i + 1] = temp;
			}
		}
}

quickRec::quickRec()
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

quickRec::quickRec(vector<Point> vec)
{
	copy(vec.begin(), vec.end(), polygon);
}

vector<vector<Point>> quickRec::algo()
{
	return quickRecAlgo(polygon);
}