#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int fntmp;

	fntmp = *a;
	*a = *b;
	*b = fntmp;
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as fnpivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *fnpivot, fnabove, fnbelow;

	fnpivot = array + right;
	for (fnabove = fnbelow = left; fnbelow < right; fnbelow++)
	{
		if (array[fnbelow] < *fnpivot)
		{
			if (fnabove < fnbelow)
			{
				swap_ints(array + fnbelow, array + fnabove);
				print_array(array, size);
			}
			fnabove++;
		}
	}

	if (array[fnabove] > *fnpivot)
	{
		swap_ints(array + fnabove, fnpivot);
		print_array(array, size);
	}

	return (fnabove);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int fnpart;

	if (right - left > 0)
	{
		fnpart = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, fnpart - 1);
		lomuto_sort(array, size, fnpart + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
