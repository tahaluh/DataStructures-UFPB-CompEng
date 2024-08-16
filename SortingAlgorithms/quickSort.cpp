#include <iostream>
#include <time.h>

#include "./Utils/utils.hpp"

using namespace std;

// quick sort algorithm
// Time complexity: O(n log n)

int partition(int arr[], int low, int high, ArrayProcessor arrayProcessor, SwapProcessor swapProcessor, CompareProcessor compareProcessor)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {

        if (compare(arr, j, high, &compareProcessor) == -1)
        {
            i++;
            swap(arr, i, j, &swapProcessor);
        }
    }
    swap(arr, i + 1, high, &swapProcessor);
    return (i + 1);
}

void quickSortRecursive(int arr[], int low, int high, ArrayProcessor arrayProcessor, SwapProcessor swapProcessor, CompareProcessor compareProcessor)
{
    if (low < high)
    {

        int pi = partition(arr, low, high, arrayProcessor, swapProcessor, compareProcessor);

        quickSortRecursive(arr, low, pi - 1, arrayProcessor, swapProcessor, compareProcessor);
        quickSortRecursive(arr, pi + 1, high, arrayProcessor, swapProcessor, compareProcessor);
    }
}

void quickSort(int *arr, int n, ArrayProcessor arrayProcessor, SwapProcessor swapProcessor, CompareProcessor compareProcessor)
{
    quickSortRecursive(arr, 0, n - 1, arrayProcessor, swapProcessor, compareProcessor);
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