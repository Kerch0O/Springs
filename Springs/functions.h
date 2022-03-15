#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Spring.h"
#include "Head.h"

sf::Vector2f operator*(sf::Vector2f v, sf::Vector2f v1);


sf::Vector2f conv(sf::Vector2f unconv);
void vCout(sf::Vector2f v, std::string s);
Head* mouseHeadInteract(sf::RenderWindow& window, std::vector<Head> &h);
float pythag(sf::Vector2f v);
void headStep(std::vector<Head>& h, std::vector<Spring> &s);
void springRectRF(std::vector<Head>& h, std::vector<Spring>& s);
