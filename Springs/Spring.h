#pragma once
#include "functions.h"

class Head;

class Spring {
public:
	float anchorL;
	float k;
	float damping;

	sf::RectangleShape rep;
	std::shared_ptr<Head> h1;
	std::shared_ptr<Head> h2;


	Spring(float a, float kc, float d);
	Spring();
};
