#include <SFML/Graphics.hpp>
#include "Grid.h"


int main()
{

    Grid grid(800, 800, 50, 50, 1); //WIDTH / HEIGHT / #of divisions in x-dir / #of divisions in y-dir / grid border

    grid.run();

}