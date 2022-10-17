#include "sort.h"

/**
 * quick_sort - applies the quicksort algorithm to the given length
 * @array: array to be sorted
 * @n: length of array
 * Return: Void
 */
void quick_sort(int array[], size_t n)
{
    srand(time(NULL));
    quicksort_recursion(array, 0, n - 1);
}

/**
 * quicksort_recursion -  applies the recursive divide and conquer
 * portion of the quicksort algorithm array... applying quicksort to the array between the low-high indexes
 * @array: array to be sorted
 * @low: low index
 * @high: high index 
 */
void quicksort_recursion(int array[], int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition(array, low, high);

        quicksort_recursion(array, low, pivot_index - 1);

        quicksort_recursion(array, pivot_index + 1, high);
    }
}

/**
 * partition - partition the array between low and high index by a
 * pivot value and returns the index of pivot
 * @array: array to be sorted
 * @low: low index
 * @high: high index
 * Return: low index
 */
int partition(int array[], int low, int high)
{
    int pivot_index = low + (rand() % (high - low)); //randomly select index between low and high

    if (pivot_index != high)
    swap(&array[pivot_index], &array[high]);

    int pivot_value = array[high];
    int i = low;
    
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot_value)
        {
            swap(&array[i], &array[j]);
            i++;
        }
    }
    swap(&array[i], &array[high]);

    return (i); 
}
