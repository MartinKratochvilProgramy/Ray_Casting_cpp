#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Button.h"


Button::Button(int _x, int _y, int _W, int _H, std::string _buttonText) {
	x = _x;
	y = _y;
	WIDTH = _W;
	HEIGHT = _H;
	buttonText = _buttonText;
}

void Button::draw(sf::RenderWindow& window) {
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	sf::RectangleShape button(sf::Vector2f(WIDTH, HEIGHT));
	if (mousePos.x >= x && mousePos.x <= WIDTH + x && mousePos.y >= y && mousePos.y <= HEIGHT + y) {
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
	text.setString(buttonText);
	text.setCharacterSize(40);
	text.setPosition(x + WIDTH/24, y + HEIGHT/12);
	text.setFillColor(sf::Color::Green);

	window.draw(button);
	window.draw(text);
}

bool Button::clicked(sf::RenderWindow& window) {
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	if (mousePos.x >= x && mousePos.x <= x + WIDTH) {
		if (mousePos.y >= y && mousePos.y <= y + HEIGHT) {
			return true;
		}
	}
	else {
		return false;
	}

}