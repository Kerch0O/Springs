#pragma once
#include "functions.h"

class Spring;

class Head {
public:
	int iS1;
	int iS2;
	sf::Vector2f acceleration;
	sf::Vector2f velocity;

	sf::CircleShape rep;

	Head(int springIndex, sf::Vector2f pos);
	Head(sf::Vector2f pos);
	void step(std::vector<Spring> &s);
};
