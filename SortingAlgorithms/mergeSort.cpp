#include <stdio.h>
#include "./Utils/utils.hpp"

// implementation of void mergeSort(int *arr, int n)

void recursiveMergeSort(int *arr, int n, int realIndexStart, ArrayProcessor arrayProcessor, SwapProcessor swapProcessor, CompareProcessor compareProcessor)
{
    if (n > 1)
    {
        int *originalArr = arr - realIndexStart;
        int mid = n / 2;
        int *left = arr;
        int *right = arr + mid;

        recursiveMergeSort(left, mid, realIndexStart, arrayProcessor, swapProcessor, compareProcessor);
        recursiveMergeSort(right, n - mid, realIndexStart + mid, arrayProcessor, swapProcessor, compareProcessor);

        int i = 0, j = 0, k = 0;
        int *temp = new int[n];

        while (i < mid && j < n - mid)
        {
            //
            if (compare(originalArr, i + realIndexStart, j + realIndexStart + mid, &compareProcessor) <= 0)
            {
                temp[k++] = left[i++];
            }
            else
            {
                temp[k++] = right[j++];
            }
        }

        while (i < mid)
        {
            temp[k++] = left[i++];
        }

        while (j < n - mid)
        {
            temp[k++] = right[j++];
        }

        for (int i = 0; i < n; i++)
        {
            arr[i] = temp[i];
            swap(originalArr, i + realIndexStart, i + realIndexStart, &swapProcessor);
        }

        delete[] temp;
    }
}

void mergeSort(int *arr, int n, ArrayProcessor arrayProcessor, SwapProcessor swapProcessor, CompareProcessor compareProcessor)
{
    recursiveMergeSort(arr, n, 0, arrayProcessor, swapProcessor, compareProcessor);
}
