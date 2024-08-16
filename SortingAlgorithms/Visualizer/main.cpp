#include <SFML/Graphics.hpp>
#include <iostream>
#include "visualizer.hpp"
#include "../Utils/utils.hpp"
#include "../bubleSort.hpp"

int main()
{
    int n = 120;
    int min = 1;
    int max = 450;
    int seed = 42;
    clock_t start, end;
    int *arr = createArray(n, min, max, seed);

    Visualizer visualizer(1200, 900, 1000, "Sorting Algorithms Visualizer", min, max, arr, n);
    sf::RenderWindow &window = visualizer.getWindow();

    while (window.isOpen())
    {
        visualizer.run(bubleSort);
        window.display();

        sf::sleep(sf::seconds(5));
        window.close();
    }

    return EXIT_SUCCESS;
}