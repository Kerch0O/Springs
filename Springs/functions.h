#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Spring.h"
#include "Head.h"


sf::Vector2f conv(sf::Vector2f unconv);
void vCout(sf::Vector2f v, std::string s);
Head* mouseHeadInteract(sf::RenderWindow& window, std::vector<Head> &h);
