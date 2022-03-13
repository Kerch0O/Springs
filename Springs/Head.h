#pragma once
#include "functions.h"

class Spring;

class Head {
public:
	std::shared_ptr<Spring> s1;
	std::shared_ptr<Spring> s2;

	sf::CircleShape rep;

	Head(Spring& spring, sf::Vector2f pos);
	Head(sf::Vector2f pos);
};
