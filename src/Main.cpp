#include "Main.hpp"
#include "Ant/Ant.hpp"
#include "Platform/Platform.hpp"

int main()
{
	srand(time(NULL));
	util::Platform platform;
	std::vector<Ant> ants;
	for (int i = 0; i < 500; i++)
	{
		ants.push_back(Ant(10, 10));
	}
#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif
	sf::RenderWindow window;
	// in Windows at least, this must be called before creating the window
	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
	// Use the screenScalingFactor
	window.create(sf::VideoMode(1000.0f * screenScalingFactor, 1000.0f * screenScalingFactor), "Ant Simulation");
	platform.setIcon(window.getSystemHandle());
	sf::Event event;
	// window.setFramerateLimit(60);
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		for (Ant& a : ants)
		{
			// std::cout << a.x << ", " << a.y << std::endl;
			a.update();
			sf::CircleShape ant(1);
			ant.setPosition(sf::Vector2f((window.getSize().x / 2) + a.x, (window.getSize().y / 2) + a.y));
			ant.setFillColor(sf::Color::Green);
			window.draw(ant);
		}

		window.display();
	}
	return 0;
}