#include <SFML/Graphics.hpp>
#include <iostream>
#include "visualizer.hpp"
#include "../Utils/utils.hpp"

int main()
{
    Visualizer visualizer(800, 600, 60, "Sorting Algorithms Visualizer");
    sf::RenderWindow &window = visualizer.getWindow();

    int n = 100;
    int nToPrint = 20;
    clock_t start, end;
    int *arr = createArray(n, 1, 100, 42);

    while (window.isOpen())
    {
        window.clear();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        visualizer.renderArray(arr, n);

        // bubleSort(arr, n, visualizer.renderArray, visualizer.renderSwap, visualizer.renderCompare);

        window.display();
    }

    return EXIT_SUCCESS;
}