#ifndef UTILS_H
#define UTILS_H
#include <functional>

using ArrayProcessor = std::function<void(int *, int)>;
using SwapProcessor = std::function<void(int, int)>;
using CompareProcessor = std::function<void(int, int)>;

void swap(int *a, int *b, SwapProcessor *swapProcessor);
int compare(int a, int b, CompareProcessor *compareProcessor);
int *createArray(int n, int min, int max, int seed);
void printArray(int *arr, int n);
void printTimeSpent(clock_t inicio, clock_t fim);

#endif
