#pragma once
#include "functions.h"

class Head;

class Spring {
public:
	float anchorL;
	float k;
	float damping;

	sf::RectangleShape rep;
	int iH1;
	int iH2;

	Spring(float a, float kc, float d, sf::Vector2f startP);
	Spring();
};
