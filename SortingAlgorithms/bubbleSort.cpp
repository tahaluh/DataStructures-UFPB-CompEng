#include "sorts.hpp"

// buble sort algorithm
// Time complexity: O(n^2)

// move the biggest element to the end of the array in each iteration swapping elements
void bubbleSort(int *arr, int n, Visualizer *visualizer)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if ((visualizer->compare(j, j + 1)) == 1)
            {
                visualizer->swap(j, j + 1);
            }
        }
    }
}