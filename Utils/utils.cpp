#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
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