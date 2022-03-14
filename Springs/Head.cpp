#include "functions.h"

Head::Head(int springIndex, sf::Vector2f pos) : iS1(springIndex), iS2(-1){

	rep.setRadius(5.0f);
	rep.setOrigin(5.0f, 5.0f);
	rep.setPosition(conv(pos));
	rep.setFillColor(sf::Color::Black);
}

Head::Head(sf::Vector2f pos) : iS1(-1), iS2(-1){

	rep.setRadius(5.0f);
	rep.setOrigin(5.0f, 5.0f);
	rep.setPosition(conv(pos));
	rep.setFillColor(sf::Color::Black);
}


