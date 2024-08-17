#include "sorts.hpp"

using namespace std;

// buble sort algorithm
// Time complexity: O(n^2)

// move the biggest element to the end of the array in each iteration

void bubbleSort(int *arr, int n, Visualizer *visualizer)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if ((visualizer->compare(j, j + 1)) == 1)
            {
                visualizer->swap(j, j + 1);
            }
        }
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
    bubleSort(arr, n);
    end = clock();

    printArray(arr, nToPrint);
    printTimeSpent(start, end);
}
*/