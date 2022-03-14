#include "functions.h"

Spring::Spring(float a, float kc, float d, sf::Vector2f startP)
	: iH1(-1), iH2(-1){

	anchorL = a;
	k = kc;
	damping = d;

	rep.setPosition(conv(startP));
}

Spring::Spring()
	: iH1(-1), iH2(-1){

	anchorL = 0.0f;
	k = 0.0f;
	damping = 0.0f;
}