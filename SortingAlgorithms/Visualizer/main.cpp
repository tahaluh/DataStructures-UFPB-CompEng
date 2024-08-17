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
    std::cout << "3 - Selection Sort" << std::endl;
    std::cout << "4 - Quick Sort" << std::endl;
    std::cout << "5 - Merge Sort" << std::endl;
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
        if (option >= 1 && option <= 5)
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
        {"Selection Sort", selectionSort},
        {"Quick Sort", quickSort},
        {"Merge Sort", mergeSort}};

    int n = 150;
    int min = 1;
    int max = n;
    int seed = 42;
    int width = 1200;
    int height = 900;

    int fps = 60 * 10;
    int *arr = createArray(n, min, max, seed);

    int option = getSort();
    sortOption selectedOption = options[option - 1];

    Visualizer visualizer(width, height, fps, selectedOption.name + " Visualizer", arr, min, max, n);
    visualizer.run(selectedOption.sorting);

    return EXIT_SUCCESS;
}