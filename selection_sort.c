#include "sort.h"

/**
 * selection_sort - Sorts an array using selection sorting technique
 *
 * @array: array been passed to be sorted
 * @n: size of array
 *
 * Return: void
 */
void selection_sort(int *array, size_t n)
{
    size_t i, j;
    int temp;

    for (i = 0; i < n-1; i++)
    {
        int min = i;
        for (j= i+1; j<n; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(&array[i], &array[min]);
        }
    }
}
