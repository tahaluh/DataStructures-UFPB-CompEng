#include <iostream>
#include <time.h>

#include "./Utils/utils.hpp"

using namespace std;

// selection sort algorithm
// Time complexity: O(n^2)

// select the biggest element and move it to the end of the array with just one swap
void selectionSort(int *arr, int n, ArrayProcessor arrayProcessor, SwapProcessor swapProcessor, CompareProcessor compareProcessor)
{
    int maxIndex;
    for (int i = n - 1; i >= 0; i--)
    {
        maxIndex = i;

        for (int j = i; j >= 0; j--)
        {
            if (compare(arr, j, maxIndex, &compareProcessor) == 1)
            {
                maxIndex = j;
            }
        }

        swap(arr, i, maxIndex, &swapProcessor);
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
    selectionSort(arr, n);
    end = clock();

    printArray(arr, nToPrint);
    printTimeSpent(start, end);
}
*/