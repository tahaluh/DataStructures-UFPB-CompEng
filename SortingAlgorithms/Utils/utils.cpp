#include <iostream>
#include <functional>
#include "utils.hpp"

using namespace std;

void swap(int *arr, int a, int b, SwapProcessor *swapProcessor = nullptr)
{
    if (swapProcessor)
    {
        (*swapProcessor)(arr, a, b);
    }
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int compare(int *arr, int a, int b, CompareProcessor *compareProcessor = nullptr)
{
    if (compareProcessor)
    {
        (*compareProcessor)(arr, a, b);
    }
    if (arr[a] > arr[b])
    {
        return 1;
    }
    if (arr[a] < arr[b])
    {
        return -1;
    }
    return 0;
}

int *createArray(int n, int min, int max, int seed)
{
    int *arr = (int *)malloc(n * sizeof(int));
    srand(seed);
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % (max - min + 1) + min;
    }
    return arr;
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printTimeSpent(clock_t start, clock_t end)
{
    double timeSpent = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "Tempo gasto: " << timeSpent << "s" << endl;
}