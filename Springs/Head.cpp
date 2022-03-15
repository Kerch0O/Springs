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

void Head::step(std::vector<Spring> &s, std::vector<Head> &h) {
	sf::Vector2f d = conv(s[iS1].rep.getPosition()) - conv(rep.getPosition());
	//Make absolute
	d.x = d.x < 0 ? d.x * -1 : d.x;
	d.y = d.y < 0 ? d.y * -1 : d.y;

	float zeta = atan(d.x / d.y);
	float l = pythag(d);

	float Fs = -s[iS1].k * (l - s[iS1].anchorL);

	sf::Vector2f a(1.0f, 1.0f);
	if (s[iS1].rep.getPosition().x > rep.getPosition().x) {
		a.x *= -1.0f;
	}
	if (conv(s[iS1].rep.getPosition()).y < conv(rep.getPosition()).y) {
		a.y *= -1.0f;
	}


	acceleration = sf::Vector2f(Fs * sin(zeta), Fs * cos(zeta));
	acceleration = acceleration * a;

	acceleration += sf::Vector2f(0.0f, 0.01f); //Apply gravity

	if (iS2 != -1) {
		//Calculate reverse force according to Newton's third law
		//Without doing this, they become very very elastic as there is a snowball of force from distances becoming very close
		//This makes the individual heads repel eachover via the spring, removing this error

		d = conv(rep.getPosition()) - conv(h[iS2 + 1].rep.getPosition());
		//Make absolute
		d.x = d.x < 0 ? d.x * -1 : d.x;
		d.y = d.y < 0 ? d.y * -1 : d.y;

		zeta = atan(d.x / d.y);
		l = pythag(d);

		float Fs2 = s[iS2].k * (l - s[iS2].anchorL);

		sf::Vector2f newF = sf::Vector2f(Fs2 * sin(zeta), Fs2 * cos(zeta));
		a = sf::Vector2f(1.0f, 1.0f);

		if (rep.getPosition().x > h[iS2 + 1].rep.getPosition().x) {
			a.x *= -1.0f;
		}
		if (conv(rep.getPosition()).y < conv(h[iS2 + 1].rep.getPosition()).y) {
			a.y *= -1.0f;
		}

		newF = newF * a;

		acceleration += newF;

	}

	velocity += acceleration;

	velocity *= s[iS1].damping;

	rep.move(velocity);

	//Update string position
	if(iS2 != -1)
		s[iS2].rep.setPosition(rep.getPosition());
}
