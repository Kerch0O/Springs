#include "functions.h"

Head::Head(int springIndex, sf::Vector2f pos) : 
	iS1(springIndex), iS2(-1), acceleration(sf::Vector2f(0.0f, 0.0f)), velocity(sf::Vector2f(0.0f, 0.0f)){

	rep.setRadius(5.0f);
	rep.setOrigin(5.0f, 5.0f);
	rep.setPosition(conv(pos));
	rep.setFillColor(sf::Color::Black);
}

Head::Head(sf::Vector2f pos)
	: iS1(-1), iS2(-1), acceleration(sf::Vector2f(0.0f, 0.0f)), velocity(sf::Vector2f(0.0f, 0.0f)){

	rep.setRadius(5.0f);
	rep.setOrigin(5.0f, 5.0f);
	rep.setPosition(conv(pos));
	rep.setFillColor(sf::Color::Black);
}

void Head::step(std::vector<Spring> &s) {
	sf::Vector2f d = conv(s[iS1].rep.getPosition()) - conv(rep.getPosition());
	//Make absolute
	vCout(d, "D1");
	d.x = d.x < 0 ? d.x * -1 : d.x;
	d.y = d.y < 0 ? d.y * -1 : d.y;
	vCout(d, "D2");

	float zeta = atan(d.x / d.y);
	std::cout << "Zeta: " << zeta << std::endl;
	float l = pythag(d);
	std::cout << "Length: " << l << std::endl;

	float Fs = -s[iS1].k * (l - s[iS1].anchorL);
	std::cout << "Length force: " << Fs << std::endl;

	sf::Vector2f a(1.0f, 1.0f);
	if (s[iS1].rep.getPosition().x > rep.getPosition().x) {
		a.x *= -1.0f;
	}
	if (conv(s[iS1].rep.getPosition()).y < conv(rep.getPosition()).y) {
		a.y *= -1.0f;
	}

	vCout(a, "a");

	acceleration = sf::Vector2f(Fs * sin(zeta), Fs * cos(zeta));
	acceleration = acceleration * a;

	vCout(acceleration, "Acceleration");
	velocity += acceleration;
	vCout(velocity, "Velocity");

	velocity *= s[iS1].damping;

	rep.move(velocity);
}
