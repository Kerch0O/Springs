#include "functions.h"


int main() {

	//Window
	sf::RenderWindow window(sf::VideoMode(1200, 900), "Springs", sf::Style::Default);

	float headNum = 2; // >1
	float anchorLengthG = 100.0f;

	sf::Vector2f startingPos(600.0f, 600.0f);

	std::vector<Spring> springs;
	std::vector<Head> heads;

	heads.push_back(Head(startingPos));

	for (int i = 0; i < headNum - 1; i++) {
		springs.push_back(Spring(anchorLengthG, 0.001f, 0.99f));
		heads.push_back(Head(springs[springs.size() - 1], sf::Vector2f(startingPos.x, startingPos.y + (i + 1) * anchorLengthG)));

		springs[springs.size() - 1].h1 = std::make_unique<Head>(heads[i]);
		springs[springs.size() - 1].h2 = std::make_unique<Head>(heads[i + 1]);
	}

	while (window.isOpen()) {
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		window.clear(sf::Color::White);

		for (auto& x : heads) {
			window.draw(x.rep);
		}

		window.display();
	}

	return 0;
}