#include "sorts.hpp"

// implementation of void mergeSort(int *arr, int n)

void recursiveMergeSort(int *arr, int n, int realIndexStart, Visualizer *visualizer)
{
    if (n > 1)
    {
        int *originalArr = arr - realIndexStart;
        int mid = n / 2;
        int *left = arr;
        int *right = arr + mid;

        recursiveMergeSort(left, mid, realIndexStart, visualizer);
        recursiveMergeSort(right, n - mid, realIndexStart + mid, visualizer);

        int i = 0, j = 0, k = 0;
        int *temp = new int[n];

        while (i < mid && j < n - mid)
        {
            //
            if (visualizer->compare(i + realIndexStart, j + realIndexStart + mid) <= 0)
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
            visualizer->swap(i + realIndexStart, i + realIndexStart);
        }

        delete[] temp;
    }
}

void mergeSort(int *arr, int n, Visualizer *visualizer)
{
    recursiveMergeSort(arr, n, 0, visualizer);
}