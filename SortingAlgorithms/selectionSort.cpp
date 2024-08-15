#include <iostream>
#include <time.h>

#include "../Utils/utils.h"

using namespace std;

// selection sort algorithm
// Time complexity: O(n^2)

// select the biggest element and move it to the end of the array with just one swap
void selectionSort(int *arr, int n)
{
    int maxIndex;
    for (int i = 0; i < n - 1; i++)
    {
        maxIndex = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                maxIndex = j;
            }
        }
        swap(&arr[maxIndex], &arr[n - i - 1]);
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
    selectionSort(arr, n);
    end = clock();

    printArray(arr, nToPrint);
    printTimeSpent(start, end);
}