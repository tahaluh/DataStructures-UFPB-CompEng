#include <SFML/Graphics.hpp>
#include <iostream>
#include "visualizer.hpp"
#include "../Utils/utils.hpp"
#include "../bubleSort.hpp"

int main()
{
    int n = 100;
    int min = 1;
    int max = 100;
    int seed = 42;
    int nToPrint = 20;
    clock_t start, end;

    int *arr = createArray(n, min, max, seed);

    Visualizer visualizer(800, 600, 500, "Sorting Algorithms Visualizer", min, max, arr, n);
    sf::RenderWindow &window = visualizer.getWindow();

    window.clear();
    int randomIndex = rand() % n;
    int randomIndex2 = rand() % n;

    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    bubleSort(
        arr, n,
        [&visualizer](int *array, int size)
        { visualizer.renderArray(array, size); },
        [&visualizer](int *array, int indexA, int indexB)
        { visualizer.renderSwap(array, indexA, indexB); },
        [&visualizer](int *array, int indexA, int indexB)
        { visualizer.renderCompare(array, indexA, indexB); });

    window.display();

    return EXIT_SUCCESS;
}