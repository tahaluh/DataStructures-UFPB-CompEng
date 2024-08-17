#include <functional>
#include "Utils/utils.hpp"
#include "Visualizer/visualizer.hpp"

// define a type Sorting that is a function that returns void and receives a int array, a int and a Visualizer
using Sorting = std::function<void(int *, int, Visualizer *)>;

void bubbleSort(int *arr, int n, Visualizer *visualizer);
void insertionSort(int *arr, int n, Visualizer *visualizer);
void quickSort(int *arr, int n, Visualizer *visualizer);
void selectionSort(int *arr, int n, Visualizer *visualizer);
void mergeSort(int *arr, int n, Visualizer *visualizer); // wip