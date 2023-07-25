#include "sort.h"

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
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *fnmin;
	size_t m, n;

	if (array == NULL || size < 2)
		return;

	for (m = 0; m < size - 1; m++)
	{
		fnmin = array + m;
		for (n = m + 1; n < size; n++)
			fnmin = (array[n] < *fnmin) ? (array + n) : fnmin;

		if ((array + m) != fnmin)
		{
			swap_ints(array + m, fnmin);
			print_array(array, size);
		}
	}
}
