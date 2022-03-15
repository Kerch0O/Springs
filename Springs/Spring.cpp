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

	sf::Vector2f d = conv(rep.getPosition()) - conv(h[iH2].rep.getPosition());
	float l = pythag(d);
	float zeta = atan(d.y / d.x);

	if (d.x > 0.0f && d.y < 0.0f)zeta += 3.1415926f / 2.0f;
	else if (d.x < 0.0f && d.y < 0.0f)zeta += 3.1415926f;
	else if (d.x < 0.0f && d.y > 0.0f)zeta += 3.1415926f * (3.0f / 2.0f); //All in radians
	//PI radians = 180 degrees
	//Fix this^
	rep.setSize(sf::Vector2f(l, 5.0f));
	rep.setRotation(zeta * 180.0f / 3.14159265358979f);
}