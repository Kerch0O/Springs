#include "functions.h"

Head::Head(Spring &spring, sf::Vector2f pos) : s1(nullptr), s2(nullptr){

	rep.setRadius(5.0f);
	rep.setOrigin(5.0f, 5.0f);
	rep.setPosition(conv(pos));
}

Head::Head(sf::Vector2f pos) : s1(nullptr), s2(nullptr){


	rep.setRadius(5.0f);
	rep.setOrigin(5.0f, 5.0f);
	rep.setPosition(conv(pos));
}

