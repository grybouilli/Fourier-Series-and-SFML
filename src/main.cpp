#include <SFML/Graphics.hpp>
#include "hdr/FourierCircle.hpp"
#include "hdr/LineShape.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(2000, 1000), "fourier series");

	float radius = 150.f;
	FourierCircle circle(radius, 20);
	circle.setPosition(350.f, 350.f);

	//shape for the signal
	LineShape curve {};

	sf::Clock clock;
	sf::Time elapsed = sf::Time::Zero;

	//line between point on the fourier circles and the signal
	sf::VertexArray line(sf::Lines, 2);
	line[0].position = circle.getFPointPosition();
	sf::Color lineColor(255,0,0);
	line[0].color = lineColor;
	line[1].color = lineColor;

	while(window.isOpen())
	{
		sf::Event event {};
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}

		elapsed = clock.restart();
		circle.update(elapsed);
		curve.update(elapsed);

		//adds a new vertex to the signal shape
		sf::Vector2f newPosition(circle.getPosition().x + 350.f, circle.getFPointPosition().y);
		curve.push(newPosition, lineColor);

		line[0].position = circle.getFPointPosition();
		line[1].position = newPosition;

		window.clear();
		window.draw(circle);
		window.draw(curve);
		window.draw(line);
		window.display();
	}
	return 0;
}