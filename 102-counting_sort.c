#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int fnmax, m;

	for (fnmax = array[0], m = 1; m < size; m++)
	{
		if (array[m] > fnmax)
			fnmax = array[m];
	}

	return (fnmax);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *fncount, *fnsorted, fnmax, m;

	if (array == NULL || size < 2)
		return;

	fnsorted = malloc(sizeof(int) * size);
	if (fnsorted == NULL)
		return;
	fnmax = get_max(array, size);
	fncount = malloc(sizeof(int) * (fnmax + 1));
	if (fncount == NULL)
	{
		free(fnsorted);
		return;
	}

	for (m = 0; m < (fnmax + 1); m++)
		fncount[m] = 0;
	for (m = 0; m < (int)size; m++)
		fncount[array[m]] += 1;
	for (m = 0; m < (fnmax + 1); m++)
		fncount[m] += fncount[m - 1];
	print_array(fncount, fnmax + 1);

	for (m = 0; m < (int)size; m++)
	{
		fnsorted[fncount[array[m]] - 1] = array[m];
		fncount[array[m]] -= 1;
	}

	for (m = 0; m < (int)size; m++)
		array[m] = fnsorted[m];

	free(fnsorted);
	free(fncount);
}
