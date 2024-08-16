#include <functional>
#include "Utils/utils.hpp"

void bubleSort(int *arr, int n, ArrayProcessor arrayProcessor, SwapProcessor swapProcessor, CompareProcessor compareProcessor);
void insertionSort(int *arr, int n, ArrayProcessor arrayProcessor, SwapProcessor swapProcessor, CompareProcessor compareProcessor);
void mergeSort(int *arr, int n, ArrayProcessor arrayProcessor, SwapProcessor swapProcessor, CompareProcessor compareProcessor);