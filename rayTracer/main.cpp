#include <SFML/Graphics.hpp>
#include "Grid.h"

//Creates 800x800 grid with 50x50 divisions
//Press F to show rays, R to hide rays
//left click creates blocks on grid
//A and D rotates rays

int main()
{
    Grid grid(800, 800, 50, 50, 1); //WIDTH / HEIGHT / #of divisions in x-dir / #of divisions in y-dir / grid border

    grid.run();

}