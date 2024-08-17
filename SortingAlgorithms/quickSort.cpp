#include "sorts.hpp"

using namespace std;

// quick sort algorithm
// Time complexity: O(n log n)

int partition(int arr[], int low, int high, Visualizer *visualizer)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {

        if (visualizer->compare(j, high) == -1)
        {
            i++;
            visualizer->swap(i, j);
        }
    }
    visualizer->swap(i + 1, high);
    return (i + 1);
}

void quickSortRecursive(int arr[], int low, int high, Visualizer *visualizer)
{
    if (low < high)
    {

        int pi = partition(arr, low, high, visualizer);

        quickSortRecursive(arr, low, pi - 1, visualizer);
        quickSortRecursive(arr, pi + 1, high, visualizer);
    }
}

void quickSort(int *arr, int n, Visualizer *visualizer)
{
    quickSortRecursive(arr, 0, n - 1, visualizer);
}

/*
int main()
{
    int n = 10000000;
    int nToPrint = 20;
    clock_t start, end;

    int *arr = createArray(n, 1, 100, 42);
    printArray(arr, nToPrint);

    start = clock();
    quickSort(arr, n);
    end = clock();

    printArray(arr, nToPrint);
    printTimeSpent(start, end);
}
*/