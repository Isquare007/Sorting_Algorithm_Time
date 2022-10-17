#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stddef.h>

//printing array prototype
void print_array(const int array[], size_t size);

//swapping prototype
void swap(int *a, int *b);

//print time prototype
void print_time(char *name, clock_t time);

//boolean typedef
typedef enum boolll
{
	false,
	true = 1
} bool;

//prototypes
void bubble_sort(int array[], size_t n);
void selection_sort(int *array, size_t n);
void insert_sort(int *array, size_t n);
//heap sort functions
void heapify(int array[], int i, size_t n);
void heap_sort(int array[], size_t n);
//Merge sort functions
void merge_sort(int array[], size_t n);
void merge_sort_recursion(int array[], int l, int r);
void merge_sorted_arrays(int array[], int l, int m, int r);
//Quick sort functions
void quick_sort(int array[], size_t n);
void quicksort_recursion(int array[], int low, int high);
int partition(int array[], int low, int high);
//shell sort function
void shell_sort(int array[], int n);


#endif /*SORT_H*/
