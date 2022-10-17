#include "sort.h"

/**
 * bubble_sort - sort an array using bubble sort technique
 *
 * @array: array been passed for sorting
 * @n: size of array been passed
 *
 * Return: void
 */
void bubble_sort(int array[], size_t n)
{
    size_t i, j;
    int temp;
    bool bubble = false;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                bubble = true;
                //print_array(array, n);
            }
            
        }
        if (bubble == false)
        break;
    }
}
