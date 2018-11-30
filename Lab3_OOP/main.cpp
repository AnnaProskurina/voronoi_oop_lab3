#include <iostream>
#include "Polygon_plus.h"
#include <SFML/Graphics.hpp>
#include "Algorithms.h"


using namespace std;


int main()
{
	/*
	Point p1(0.0, 0.0);
	Point p2(0.0, 200.0);
	Point p3(200.0, 200.0);
	Point p4(200.0, 0.0);
	Point p5(100.0, 100.0);
	Point p6(100.0, 200.0);
	Point p7(200.0, 100.0);
	Point p8(0.0, 100.0);
	vector<Point> grahamTest = { p1, p2,  p5, p3, p4, p6, p7, p8 };

	vector<Point> res = GrahamAlgo(grahamTest);

	sf::RenderWindow  window(sf::VideoMode(1000, 1000), "LAB 3");
	sf::VertexArray lines(sf::Lines, res.size());

	for (int i = 0; i < res.size(); i++) 
	{
		lines[i].position = sf::Vector2f(res[i].getX(), res[i].getY());

		lines[i].color = sf::Color::White;
	}

	sf::CircleShape points[10];

	for (int i = 0; i < grahamTest.size(); i++)
	{
		points[i].setPosition (sf::Vector2f(grahamTest[i].getX(), grahamTest[i].getY()));
		points[i].setFillColor(sf::Color::Red);
		points[i].setRadius(4);
	}

	while (window.isOpen()) 
	{
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		for (int i = 0; i < 10; i++)
		{
			window.draw(points[i]);
		}
		window.draw(lines);
		window.display();
	}
	
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i].getX() << "  " << res[i].getY() << "  " << endl;
	}
	*/
	system("pause");
	return 0;
}