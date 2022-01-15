#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <SFML/Graphics.hpp>
#define PI 3.14159265

class Grid
{
public:
	int WIDTH, HEIGHT;
	int Nx, Ny;
	int dx, dy;
	int border;
	int numberOfRays = 120;
	float rotation = 0.1;
	float dfi = 45 / (static_cast<float>(numberOfRays)) * PI / 180.0;
	float fi;
	float rayLenght = 400.0f;

	int nxCell, nyCell;
	float dxCell, dyCell;
	float dxWall, dyWall;
	float tanFi;
	float xStart, yStart;
	float L;

	bool renderRaysSwitch = false;

	Grid(int WIDHT, int HEIGHT, int Nx, int Ny, int border);

	std::vector<std::vector<int>> gridMatrix;

	void print_stats();

	void print_grid();

	void run();

private:
	void renderGrid(sf::RenderWindow& window);

	void renderRays(sf::RenderWindow& window);

	void changeGridOnClick(sf::RenderWindow& window);

	void resetGrid();

	void drawInstructions(sf::RenderWindow& window);

};
