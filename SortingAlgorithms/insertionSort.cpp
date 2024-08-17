#include "sorts.hpp"

// insertion sort algorithm
// Time complexity: O(n^2)

// always keep the left side of the array sorted inserting the current element in the right position
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