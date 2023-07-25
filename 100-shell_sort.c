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
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t fngap, m, n;

	if (array == NULL || size < 2)
		return;

	for (fngap = 1; fngap < (size / 3);)
		fngap = fngap * 3 + 1;

	for (; fngap >= 1; fngap /= 3)
	{
		for (m = fngap; m < size; m++)
		{
			n = m;
			while (n >= fngap && array[n - fngap] > array[n])
			{
				swap_ints(array + n, array + (n - fngap));
				n -= fngap;
			}
		}
		print_array(array, size);
	}
}
