#include "sort.h"

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        i++;
    }
    printf("\n");
}

/**
 * swap - swap the values of an array
 *
 * @a: FIrst value
 * @b: second value
 *
 * Return: void
 */
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * print_time - prints the time taken for sorting
 *
 * @name: name of the sorting technique
 * @time: time at the start of the sorting
 * Return: void
 */
void print_time(char *name, clock_t time)
{
    time = clock() - time;

    float time_taken = ((float)time)/CLOCKS_PER_SEC; // in seconds

    printf("%s took %f seconds to sort \n", name, time_taken);
    printf("\n");
}
