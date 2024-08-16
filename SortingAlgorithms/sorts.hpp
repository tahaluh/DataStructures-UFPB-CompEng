#include <functional>
#include "Utils/utils.hpp"

void bubbleSort(int *arr, int n, ArrayProcessor arrayProcessor, SwapProcessor swapProcessor, CompareProcessor compareProcessor);
void insertionSort(int *arr, int n, ArrayProcessor arrayProcessor, SwapProcessor swapProcessor, CompareProcessor compareProcessor);
void quickSort(int *arr, int n, ArrayProcessor arrayProcessor, SwapProcessor swapProcessor, CompareProcessor compareProcessor);
void selectionSort(int *arr, int n, ArrayProcessor arrayProcessor, SwapProcessor swapProcessor, CompareProcessor compareProcessor);
void mergeSort(int *arr, int n, ArrayProcessor arrayProcessor, SwapProcessor swapProcessor, CompareProcessor compareProcessor); // wip