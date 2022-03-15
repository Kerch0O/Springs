#include "functions.h"


int main() {

	//Window
	sf::RenderWindow window(sf::VideoMode(1200, 900), "Springs", sf::Style::Default);

	int headNum = 6; // >1
	float anchorLengthG = 40.0f;
	float damping = 0.991f;
	float springC = 0.002f;

	sf::Vector2f startingPos(600.0f, 700.0f);

	std::vector<Spring> springs;
	std::vector<Head> heads;

	heads.push_back(Head(startingPos));

	for (int i = 0; i < headNum - 1; i++) {
		springs.push_back(Spring(anchorLengthG, springC, damping, sf::Vector2f(conv(heads[i].rep.getPosition()))));
		heads.push_back(Head(springs.size() - 1, sf::Vector2f(startingPos.x, startingPos.y - (i + 1) * anchorLengthG)));

		springs[springs.size() - 1].iH1 = i;
		springs[springs.size() - 1].iH2 = i + 1;

		heads[i].iS2 = i;
	}


	//Mouse interactions
	bool pressed = false;
	Head* headClicked = nullptr;

	while (window.isOpen()) {
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
				pressed = true;
				headClicked = mouseHeadInteract(window, heads);
				break;
			case sf::Event::MouseButtonReleased:
				pressed = false;
				headClicked = nullptr;
				break;
			case sf::Event::TextEntered:
				if (evnt.text.unicode == 's') {
					headStep(heads, springs);
				}
			}
		}

		if (pressed && headClicked != nullptr && headClicked->iS1 != -1) {
			headClicked->rep.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
		}

		headStep(heads, springs);
		springRectRF(heads, springs);

		window.clear(sf::Color::White);

		for (auto& x : heads)window.draw(x.rep);
		for (auto& x : springs)window.draw(x.rep);

		window.display();
	}

	return 0;
}