#ifndef UTILS_H
#define UTILS_H
#include <functional>

using ArrayProcessor = std::function<void(int *, int)>;
using SwapProcessor = std::function<void(int *, int, int)>;
using CompareProcessor = std::function<void(int *, int, int)>;

void swap(int *arr, int a, int b, SwapProcessor *SwapProcessor);
int compare(int *arr, int a, int b, CompareProcessor *CompareProcessor);
int *createArray(int n, int min, int max, int seed);
void printArray(int *arr, int n);
void printTimeSpent(clock_t inicio, clock_t fim);

#endif
