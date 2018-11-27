#include <iostream>
#include "Polygon_plus.h"
#include <SFML/Graphics.hpp>
#include "Algorithms.h"


using namespace std;


int main()
{
	/*sf::ConvexShape s;
	s.setPointCount(3);
	s.setPoint(0, sf::Vector2f(5, 5));
	s.setPoint(1, sf::Vector2f(25, 25));
	s.setPoint(2, sf::Vector2f(50, 5));

	sf::CircleShape shape1(100.f);
	shape1.setFillColor(sf::Color::Red);


	sf::RenderWindow wind(sf::VideoMode(400, 400), "SFML works!");


	while (wind.isOpen())
	{
		sf::Event event;

		while (wind.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				wind.close();
		}
		wind.clear();
		//wind.draw(shape1);

		wind.draw(s);
		wind.display();
	}
*/

	int quantityP = 20;
	Point p1(0.0, 0.0);
	Point p2(0.0, 20.0);
	Point p3(20.0, 20.0);
	Point p4(20.0, 0.0);
	Point p5(10.0, 10.0);
	Point p6(10.0, 20.0);
	Point p7(20.0, 10.0);
	Point p8(0.0, 10.0);
	vector<Point> grahamTest = { p1, p2,  p5, p3, p4, p6, p7, p8 };

	vector<Point> res; // just to test
	
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i].getX() << "  " << res[i].getY() << "  "<<endl;
	}
	
	system("pause");
	return 0;
}