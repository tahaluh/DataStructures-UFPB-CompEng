#include <SFML/Graphics.hpp>
#include <iostream>
#include "visualizer.hpp"
#include "../Utils/utils.hpp"
#include "../sorts.hpp"

int main()
{
    int n = 150;
    int min = 1;
    int max = 100;
    int seed = 42;
    int width = 1200;
    int height = 900;

    int fps = 500;
    int *arr = createArray(n, min, max, seed);

    Visualizer visualizer(width, height, fps, "Sorting Algorithms Visualizer", min, max, arr, n);
    sf::RenderWindow &window = visualizer.getWindow();

    while (window.isOpen())
    {
        visualizer.run(insertionSort);
        window.display();

        sf::sleep(sf::seconds(5));
        window.close();
    }

    return EXIT_SUCCESS;
}