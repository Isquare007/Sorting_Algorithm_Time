#include "sort.h"
/**
 * heapify - recurssive function; makes a max heap binary tree from the array
 * @array: array to be heapified
 * @i: index to start heapify
 * @n: size of array
 * Return: void
 */

void heapify(int *array, int i, size_t n)
{
	int largest = i;
	int l = (2 * i);
	int r = (2 * i) + 1;
	
	if (l < n && array[l] > array[largest])
		largest = l;
	if (r < n && array[r] > array[largest])
		largest = r;
	
	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		heapify(array, largest, n);
	}
}

/**
 * heap_sort - sort the heapifeld array
 * @array: array to be sorted
 * @n: size of array
 * Return: void
 */
void heap_sort(int array[], size_t n)
{
    int i;

    for (i = (n/2)-1; i >= 0; i--)
    {
        heapify(array, i, n);
    }
    for (i = n-1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        heapify(array, 0, i);
    }
}
