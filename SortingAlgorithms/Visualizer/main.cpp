#include <SFML/Graphics.hpp>
#include <iostream>
#include "visualizer.hpp"
#include "../Utils/utils.hpp"
#include "../sorts.hpp"

void menu()
{
    std::cout << "------ Sorting Algorithms Menu ------" << std::endl;
    std::cout << "1 - Bubble Sort" << std::endl;
    std::cout << "2 - Insertion Sort" << std::endl;
    std::cout << "3 - Quick Sort" << std::endl;
    std::cout << "4 - Selection Sort" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Please select an option (1-5): " << std::endl;
}

typedef struct sortOption
{
    std::string name;
    Sorting sorting;
} sortOption;

int getSort()
{
    int option;
    while (1)
    {
        menu();
        std::cin >> option;
        if (option >= 1 && option <= 4)
            break;
        else
            std::cout << "Invalid option" << std::endl;
    }

    return option;
}

int main()
{
    sortOption options[] = {
        {"Bubble Sort", bubbleSort},
        {"Insertion Sort", insertionSort},
        {"Quick Sort", quickSort},
        {"Selection Sort", selectionSort}};

    int n = 150;
    int min = 1;
    int max = 100;
    int seed = 42;
    int width = 1200;
    int height = 900;

    int fps = 500;
    int *arr = createArray(n, min, max, seed);

    int option = getSort();
    sortOption selectedOption = options[option - 1];

    Visualizer visualizer(width, height, fps, selectedOption.name + " Visualizer", min, max, arr, n);
    sf::RenderWindow &window = visualizer.getWindow();

    visualizer.run(selectedOption.sorting);

    window.display();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return EXIT_SUCCESS;
}