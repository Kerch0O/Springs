#include "functions.h"

sf::Vector2f conv(sf::Vector2f unconv) {
	return sf::Vector2f(unconv.x, 900 - unconv.y);
}