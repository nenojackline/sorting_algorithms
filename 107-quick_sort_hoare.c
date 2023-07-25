#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

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
 * hoare_partition - Order a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the fnpivot.
 * Prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int fnpivot, fnabove, fnbelow;

	fnpivot = array[right];
	for (fnabove = left - 1, fnbelow = right + 1; fnabove < fnbelow;)
	{
		do {
			fnabove++;
		} while (array[fnabove] < fnpivot);
		do {
			fnbelow--;
		} while (array[fnbelow] > fnpivot);

		if (fnabove < fnbelow)
		{
			swap_ints(array + fnabove, array + fnbelow);
			print_array(array, size);
		}
	}

	return (fnabove);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int fnpart;

	if (right - left > 0)
	{
		fnpart = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, fnpart - 1);
		hoare_sort(array, size, fnpart, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
