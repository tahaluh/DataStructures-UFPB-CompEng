#include <iostream>
#include <time.h>

#include "../Utils/utils.h"

using namespace std;

// insertion sort algorithm
// Time complexity: O(n^2)

// always keep the left side of the array sorted
void insertionSort(int *arr, int n)
{
    int swapIndex;
    for (int i = 1; i < n; i++)
    {
        swapIndex = i;
        while (swapIndex > 0 && arr[swapIndex] < arr[swapIndex - 1])
        {
            swap(&arr[swapIndex], &arr[swapIndex - 1]);
            swapIndex--;
        }
    }
}

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