#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

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
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t fnleft, fnright, fnlarge;

	fnleft = 2 * root + 1;
	fnright = 2 * root + 2;
	fnlarge = root;

	if (fnleft < base && array[fnleft] > array[fnlarge])
		fnlarge = fnleft;
	if (fnright < base && array[fnright] > array[fnlarge])
		fnlarge = fnright;

	if (fnlarge != root)
	{
		swap_ints(array + root, array + fnlarge);
		print_array(array, size);
		max_heapify(array, size, base, fnlarge);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int m;

	if (array == NULL || size < 2)
		return;

	for (m = (size / 2) - 1; m >= 0; m--)
		max_heapify(array, size, size, m);

	for (m = size - 1; m > 0; m--)
	{
		swap_ints(array, array + m);
		print_array(array, size);
		max_heapify(array, size, m, 0);
	}
}
