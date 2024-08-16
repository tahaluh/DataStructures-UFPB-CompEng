#include <iostream>
#include <time.h>
#include <functional>

#include "Utils/utils.hpp"

using namespace std;

using ArrayProcessor = std::function<void(int *, int)>;
using SwapProcessor = std::function<void(int, int)>;
using CompareProcessor = std::function<void(int, int)>;

// buble sort algorithm
// Time complexity: O(n^2)

// move the biggest element to the end of the array in each iteration
void bubleSort(int *arr, int n, ArrayProcessor arrayProcessor = nullptr, SwapProcessor swapProcessor = nullptr, CompareProcessor compareProcessor = nullptr)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (compare(arr[j], arr[j + 1], compareProcessor) == 1)
            {
                swap(&arr[j], &arr[j + 1], swapProcessor);
                if (arrayProcessor)
                {
                    arrayProcessor(arr, n);
                }
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