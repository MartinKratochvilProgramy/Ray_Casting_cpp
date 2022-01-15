#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Button.h"


Button::Button(int ix, int iy, int iW, int iH, std::string iName) {
	x = ix;
	y = iy;
	buttonWIDTH = iW;
	buttonHEIGHT = iH;
	name = iName;
}

void Button::draw(sf::RenderWindow& window) {
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	sf::RectangleShape button(sf::Vector2f(buttonWIDTH, buttonHEIGHT));
	if (mousePos.x >= x && mousePos.x <= buttonWIDTH + x && mousePos.y >= y && mousePos.y <= buttonHEIGHT + y) {
		button.setFillColor(sf::Color::White);
	}
	else {
		button.setFillColor(sf::Color::Black);
	}

	button.setPosition(x, y);

	sf::Font font;
	font.loadFromFile("Fonts/OpenSans-Bold.ttf");
	sf::Text text;
	text.setFont(font);
	text.setString(name);
	text.setCharacterSize(40);
	text.setPosition(x + buttonWIDTH/24, y + buttonHEIGHT/12);
	text.setFillColor(sf::Color::Green);

	window.draw(button);
	window.draw(text);
}

bool Button::clicked(sf::RenderWindow& window) {
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	if (mousePos.x >= x && mousePos.x <= x + buttonWIDTH) {
		if (mousePos.y >= y && mousePos.y <= y + buttonHEIGHT) {
			return true;
		}
	}
	else {
		return false;
	}

}