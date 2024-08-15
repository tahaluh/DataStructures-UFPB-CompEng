#ifndef UTILS_H
#define UTILS_H

void swap(int *a, int *b);
int *createArray(int n, int min, int max, int seed);
void printArray(int *arr, int n);
void printTimeSpent(clock_t inicio, clock_t fim);

#endif
