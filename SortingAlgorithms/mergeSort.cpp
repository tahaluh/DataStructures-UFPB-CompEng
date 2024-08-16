#include <iostream>
#include <time.h>

#include "./Utils/utils.hpp"

using namespace std;

// merge sort algorithm
// Time complexity: O(n log n)

// merge two sorted arrays
void mergeSort(int *arr, int n, ArrayProcessor arrayProcessor, SwapProcessor swapProcessor, CompareProcessor compareProcessor)
{
    if (n > 1)
    {
        int mid = n / 2;
        int *left = (int *)malloc(mid * sizeof(int));
        int *right = (int *)malloc((n - mid) * sizeof(int));

        for (int i = 0; i < mid; i++)
        {
            left[i] = arr[i];
        }
        for (int i = mid; i < n; i++)
        {
            right[i - mid] = arr[i];
        }

        mergeSort(left, mid);
        mergeSort(right, n - mid);

        int i = 0, j = 0, k = 0;
        while (i < mid && j < n - mid)
        {
            if (left[i] < right[j])
            {
                arr[k] = left[i];
                i++;
            }
            else
            {
                arr[k] = right[j];
                j++;
            }
            k++;
        }

        while (i < mid)
        {
            arr[k] = left[i];
            i++;
            k++;
        }

        while (j < n - mid)
        {
            arr[k] = right[j];
            j++;
            k++;
        }

        free(left);
        free(right);
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
    mergeSort(arr, n);
    end = clock();

    printArray(arr, nToPrint);
    printTimeSpent(start, end);
}
*/