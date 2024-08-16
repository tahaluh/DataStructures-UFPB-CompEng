#include <iostream>
#include <time.h>

#include "./Utils/utils.h"

using namespace std;

// quick sort algorithm
// Time complexity: O(n log n)

// choose a pivot element and move all elements smaller than the pivot to the left and all elements greater than the pivot to the right
void quickSort(int *arr, int n)
{
    if (n <= 1)
    {
        return;
    }

    int pivot = arr[n / 2];
    int i = 0, j = n - 1;
    while (i <= j)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }

    quickSort(arr, j + 1);
    quickSort(&arr[i], n - i);
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