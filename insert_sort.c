#include "sort.h"

/**
 * insert_sort - Sort an array using insert sort technique
 * @array: array to be sorted
 * @n: size of the array
 * Return: void
 */
void insert_sort(int *array, size_t n)
{
    size_t i, j;
    int temp;

    for (i = 1; i < n; i++)
    {
        temp = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > temp)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}
