#include <iostream>
#include <time.h>

#include "./Utils/utils.hpp"

using namespace std;

// insertion sort algorithm
// Time complexity: O(n^2)

// always keep the left side of the array sorted
void insertionSort(int *arr, int n, ArrayProcessor arrayProcessor, SwapProcessor swapProcessor, CompareProcessor compareProcessor)
{
    int swapIndex;
    for (int i = 1; i < n; i++)
    {
        swapIndex = i;
        // (compare(arr, j, j + 1, &compareProcessor)) == -1
        while (swapIndex > 0 && (compare(arr, swapIndex, swapIndex - 1, &compareProcessor)) == -1)
        {
            swap(arr, swapIndex, swapIndex - 1, &swapProcessor);
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