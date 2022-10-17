#include "sort.h"

/**
 * merge_sort - Performs a merge sort of the array a with the given length
 * @array: array to be merged
 * @n: size of array
 * Return: void
 */
void merge_sort(int array[], size_t n)
{
	merge_sort_recursion(array, 0, n - 1);
}
/**
 * merge_sort_recurssion - applies merge sort algorithm to array between
 * l and r index. implements the recursive divide-and-conquer step of
 * the merge sort algorithm, splitting the array portion between l...r
 * at the middle, and calling itself on each portion, before applying
 * the function to merge the sorted portions of the array that will result.
 *
 * @array: array between l and r
 * @l: left index of the array(first index)
 * @r: right index of the array(last index)
 * @Return: void
 */

void merge_sort_recursion(int array[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		merge_sort_recursion(array, l, m);
		merge_sort_recursion(array, m + 1, r);

		merge_sorted_arrays(array, l, m, r);
	}
}

/**
 * merge_sorted_arrays - merges the two sorted arrays from merge sort recursion
 * @l: left index of the array
 * @r: right index of the array
 * @m: middle of the array
 * Return: void
 */
void merge_sorted_arrays(int array[], int l, int m, int r)
{
	int left_len = m - l + 1;
	int right_len = r - m;

	int temp_left[left_len];
	int temp_right[right_len];

	int i, j, k;

	for (int i = 0; i < left_len; i++)
		temp_left[i] = array[l + i];
	for (int i = 0; i < right_len; i++)
		temp_right[i] = array[m + 1 + i];

	for (i = 0, j = 0, k = l; k <= r; k++)
	{
		if ((i < left_len) &&
				(j >= right_len || temp_left[i] <= temp_right[j]))
		{
			array[k] = temp_left[i];
			i++;
		}
		else
		{
			array[k] = temp_right[j];
			j++;
		}
	}
}
