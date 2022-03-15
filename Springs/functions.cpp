#include "functions.h"

sf::Vector2f conv(sf::Vector2f unconv) {
	return sf::Vector2f(unconv.x, 900 - unconv.y);
}

void vCout(sf::Vector2f v, std::string s) {
	if (s.size() > 0)
		std::cout << s << ": " << v.x << " " << v.y << std::endl;
	else
		std::cout << v.x << " " << v.y << std::endl;
}

Head* mouseHeadInteract(sf::RenderWindow& window,  std::vector<Head> &h) {
	sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

	for (auto& x : h) {
		if (x.rep.getGlobalBounds().intersects(sf::FloatRect(mousePos.x, mousePos.y, 1.0f, 1.0f))) {
			//Mouse hovers current head
			return &x;
		}
	}

	return nullptr;
}


float pythag(sf::Vector2f v) {
	return sqrt(v.x * v.x + v.y * v.y);
}

void headStep(std::vector<Head>& h, std::vector<Spring> &s) {
	for (auto iter = ++h.begin(); iter != h.end(); iter++)iter->step(s, h);
}

void springRectRF(std::vector<Head>& h, std::vector<Spring>& s) {
	for (auto iter = s.begin(); iter != s.end(); iter++)iter->rectRefresh(h);
}

sf::Vector2f operator*(sf::Vector2f v, sf::Vector2f v1) {
	return sf::Vector2f(v.x * v1.x, v.y * v1.y);
}
