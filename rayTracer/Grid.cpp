#include <iostream>
#include <math.h>
#include "Grid.h"
#include "Button.h"
#define PI 3.14159265


Grid::Grid(int inWIDHT, int inHEIGHT, int inNx, int inNy, int iBorder) {
	WIDTH = inWIDHT;
	HEIGHT = inHEIGHT;
	Nx = inNx;
	Ny = inNy;
	dx = WIDTH / Nx;
	dy = HEIGHT / Ny;
	border = iBorder;

	for (int i = 0; i < Ny; i++)
	{
		std::vector<int> newRow;
		for (int j = 0; j < Nx; j++)
		{
			newRow.push_back(0);
		}
		gridMatrix.push_back(newRow);
	}

}

void Grid::resetGrid() {
	for (int i = 0; i < Ny; i++)
	{
		for (int j = 0; j < Nx; j++)
		{
			gridMatrix[i][j] = 0;
		}
	}
}

void Grid::print_stats() {
	std::cout << WIDTH << std::endl;
	std::cout << HEIGHT << std::endl;
	std::cout << Nx << std::endl;
	std::cout << Ny << std::endl;
	std::cout << dx << std::endl;
	std::cout << dy << std::endl;
}

void Grid::drawInstructions(sf::RenderWindow& window) {
	sf::Font font;
	font.loadFromFile("Fonts/OpenSans-Bold.ttf");
	sf::Text instructions;
	instructions.setFont(font);
	instructions.setString("'left click' to draw obstacles\n\npress 'a' or 'd' to rotate rays\n\n");
	instructions.setCharacterSize(20);
	instructions.setPosition(850, 40);
	instructions.setFillColor(sf::Color::Green);

	window.draw(instructions);

}

void Grid::print_grid() {
	for (int i = 0; i < Ny; i++)
	{
		for (int j = 0; j < Nx; j++)
		{
			std::cout << gridMatrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Grid::renderGrid(sf::RenderWindow& window) {

	window.clear(sf::Color{ 55, 55, 55, 255 });
	for (int i = 0; i < Ny; i++)
	{
		for (int j = 0; j < Nx; j++)
		{
			//std::cout << dy << " " << dx << std::endl;
			sf::RectangleShape tile(sf::Vector2f(dx - border, dy - border));
			if (gridMatrix[i][j] == 0) { tile.setFillColor(sf::Color::Black); }
			else if (gridMatrix[i][j] == 1) { tile.setFillColor(sf::Color::Red); }

			tile.setPosition(j * dx, i * dy);
			window.draw(tile);
		}
	}

}

void Grid::renderRays(sf::RenderWindow& window) {

	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	for (int i = 0; i < numberOfRays; i++)
	{
		fi = i * dfi + rotation;

		if (fi > 2 * PI) {
			fi = fmod(fi, 2 * PI);
		}
		else if (fi < 0) {
			fi = 2 * PI + fmod(fi, 2 * PI);
		}


		nxCell = mousePos.x / dx;
		nyCell = mousePos.y / dy;

		xStart = mousePos.x;
		yStart = mousePos.y;

		bool intersects = false;
		L = 0;

		while (!intersects) {
			if (fi > 0 && fi < PI / 2) {
				tanFi = tan(fi);

				dxCell = ((nxCell + 1) * dx - xStart);
				dyCell = ((nyCell + 1) * dy - yStart);

				dxWall = dyCell / tanFi;
				dyWall = dxCell * tanFi;

				if (dxWall < dyWall) {
					nyCell += 1;
					xStart += dxWall;
					yStart += dyCell;
					L += dyCell / sin(fi);
				}
				else {
					nxCell += 1;
					xStart += dxCell;
					yStart += dyWall;
					L += dxCell / cos(fi);
				}

				if (nxCell < Nx && nxCell >= 0 && nyCell < Ny && nyCell >= 0) {
					if (gridMatrix[nyCell][nxCell] == 1) {

						break;
					}
				}
				else {
					break;

				}
			}
			else if (fi > PI / 2 && fi < PI) {
				tanFi = tan(fi - PI / 2);

				dxCell = xStart - (nxCell)*dx;
				dyCell = (nyCell + 1) * dy - yStart;

				dxWall = dyCell * tanFi;
				dyWall = dxCell / tanFi;

				if (dxWall < dyWall) {
					nyCell += 1;
					xStart -= dxWall;
					yStart += dyCell;
					L += dyCell / cos(fi - PI / 2);
				}
				else {
					nxCell -= 1;
					xStart -= dxCell;
					yStart += dyWall;
					L += dxCell / sin(fi - PI / 2);
				}

				if (nxCell < Nx && nxCell >= 0 && nyCell < Ny && nyCell >= 0) {
					if (gridMatrix[nyCell][nxCell] == 1) {

						break;
					}
				}
				else {
					break;

				}
			}
			else if (fi > PI && fi < 1.5 * PI) {
				tanFi = tan(fi);

				dxCell = xStart - (nxCell)*dx;
				dyCell = yStart - (nyCell)*dy;

				dxWall = dyCell / tanFi;
				dyWall = dxCell * tanFi;

				if (dxWall < dyWall) {
					nyCell -= 1;
					xStart -= dxWall;
					yStart -= dyCell;
					L += dyCell / sin(fi - PI);
				}
				else {
					nxCell -= 1;
					xStart -= dxCell;
					yStart -= dyWall;
					L += dxCell / cos(fi - PI);
				}

				if (nxCell < Nx && nxCell >= 0 && nyCell < Ny && nyCell >= 0) {
					if (gridMatrix[nyCell][nxCell] == 1) {

						break;
					}
				}
				else {
					break;

				}
			}
			else if (fi > 1.5 * PI && fi < 2 * PI) {
				tanFi = tan(2 * PI - fi);

				dxCell = (nxCell + 1) * dx - xStart;
				dyCell = yStart - (nyCell)*dy;

				dxWall = dyCell / tanFi;
				dyWall = dxCell * tanFi;

				if (dxWall < dyWall) {
					nyCell -= 1;
					xStart += dxWall;
					yStart -= dyCell;
					L += dyCell / sin(2 * PI - fi);
				}
				else {
					nxCell += 1;
					xStart += dxCell;
					yStart -= dyWall;
					L += dxCell / cos(2 * PI - fi);
				}

				if (nxCell < Nx && nxCell >= 0 && nyCell < Ny && nyCell >= 0) {
					if (gridMatrix[nyCell][nxCell] == 1) {

						break;
					}
				}
				else {
					break;

				}

			}
		}

		sf::Vertex line[] =
		{
			sf::Vertex(sf::Vector2f(mousePos.x, mousePos.y), sf::Color::Green),
			sf::Vertex(sf::Vector2f(mousePos.x + L * cos(fi), mousePos.y + L * sin(fi)), sf::Color::Green)
		};

		window.draw(line, 2, sf::Lines);
	}

}

void Grid::changeGridOnClick(sf::RenderWindow& window) {
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	gridMatrix[mousePos.y / dy][mousePos.x / dx] = 1;
}

void Grid::run() {
	sf::RenderWindow window{ sf::VideoMode(WIDTH * 1.5, HEIGHT), "Ray tracing" };
	window.setFramerateLimit(60);
	sf::Event event;

	bool dPressed;
	bool aPressed;
	bool buttonPressed;

	Button raysON(880, 150, 240, 60, "Show Rays");
	Button raysOFF(880, 350, 240, 60, "Hide Rays");
	Button resetGridButton(880, 550, 240, 60, "Reset Grid!");

	renderGrid(window);
	window.display();

	while (window.isOpen()) {
		
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);

		buttonPressed = false;
		dPressed = false;
		aPressed = false;

		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.close();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && dPressed == false) {
				dPressed = true;
				rotation += 0.15;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && aPressed == false) {
				rotation -= 0.15;
				aPressed = true;
			}
			else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && buttonPressed == false) {
				if (mousePos.x >= 0 && mousePos.x <= WIDTH && mousePos.y >= 0 && mousePos.y <= HEIGHT) {
					changeGridOnClick(window);
				}
				if (raysON.clicked(window) == true) {
					renderRaysSwitch = true;
				}
				if (raysOFF.clicked(window) == true) {
					renderRaysSwitch = false;
				}
				if (resetGridButton.clicked(window) == true) {
					resetGrid();
				}
				buttonPressed = true;
			}


		}

		renderGrid(window);
		drawInstructions(window);
		raysON.draw(window);
		raysOFF.draw(window);
		resetGridButton.draw(window);
		if (renderRaysSwitch == true && mousePos.x >= 0 && mousePos.x <= WIDTH && mousePos.y >= 0 && mousePos.y <= HEIGHT) {
			renderRays(window);
		}
		window.display();

	}
}