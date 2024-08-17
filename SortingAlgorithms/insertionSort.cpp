#include "sorts.hpp"

using namespace std;

// insertion sort algorithm
// Time complexity: O(n^2)

// always keep the left side of the array sorted
void insertionSort(int *arr, int n, Visualizer *visualizer)
{
    int swapIndex;
    for (int i = 1; i < n; i++)
    {
        swapIndex = i;
        // (compare(arr, j, j + 1, &compareProcessor)) == -1
        while (swapIndex > 0 && (visualizer->compare(swapIndex, swapIndex - 1)) == -1)
        {
            visualizer->compare(swapIndex, swapIndex - 1);
            visualizer->swap(swapIndex, swapIndex - 1);
            swapIndex--;
        }
    }
}

/*
int main()
{
    int n = 100000;
    int nToPrint = 20;
    clock_t start, end;

    int *arr = createArray(n, 1, 100, 42);
    printArray(arr, nToPrint);

    start = clock();
    insertionSort(arr, n);
    end = clock();

    printArray(arr, nToPrint);
    printTimeSpent(start, end);
}
*/