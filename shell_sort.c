#include "sort.h"

/**
 * shell_sort - applies shell sort algorithm by dividing array length by 2
 * @array: array to be sorted
 * @n: size of array
 * Return: void
 */

void shell_sort(int array[], int n)
{
    int i, j;
    int gap = n/2;

    while (gap >= 1)
    {
        for (j = gap; j < n; j++)
        {
            for (i = (j - gap); i >= 0; i = (i-gap))
            {
                if(array[i + gap] > array[i])
                {
                    break;
                }
                else
                {
                    swap(&array[i + gap], &array[i]);
                }
            }
        }
        gap = gap/2;
    }
}
