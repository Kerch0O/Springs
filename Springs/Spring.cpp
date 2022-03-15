#include "functions.h"

Spring::Spring(float a, float kc, float d, sf::Vector2f startP)
	: iH1(-1), iH2(-1){

	anchorL = a;
	k = kc;
	damping = d;

	rep.setPosition(conv(startP));
	rep.setFillColor(sf::Color::Black);
}

Spring::Spring()
	: iH1(-1), iH2(-1){

	anchorL = 0.0f;
	k = 0.0f;
	damping = 0.0f;
}
void Spring::rectRefresh(std::vector<Head>& h) {

	sf::Vector2f d = rep.getPosition() - h[iH2].rep.getPosition();
	sf::Vector2f d1 = d / pythag(d);
	float l = pythag(d);

	float zeta = atan(d.y / d.x) * 180.0f / 3.14159265358979f;
	if (rep.getPosition().x > h[iH2].rep.getPosition().x)zeta += 180.0f;

	rep.setSize(sf::Vector2f(l, 5.0f));
	rep.setRotation(zeta);
}