#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class Button {
public:
	Button(int, int, int, int, std::string);

	void draw(sf::RenderWindow& window);

	bool clicked(sf::RenderWindow& window);

private:
	int x, y;
	int WIDTH, HEIGHT;
	std::string buttonText;

};
