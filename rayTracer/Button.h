#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

struct Button {
	int x, y;
	int buttonWIDTH, buttonHEIGHT;
	std::string name;

	Button(int x, int y, int buttonWIDTH, int buttonHEIGHT, std::string name);

	void draw(sf::RenderWindow& window);

	bool clicked(sf::RenderWindow& window);
};
