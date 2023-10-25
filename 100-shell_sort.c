#include "sort.h"

/**
 * shell_sort - Shell sort algorithm with the Knuth sequence
 * @array: array
 * @size: size
*/

void shell_sort(int *array, size_t size)
{
	unsigned int i, j, gap = 0;
	int tmp = 0;

	if (!array || size < 2)
		return;

	while (gap < size)
		gap = (gap * 3) + 1;

	for (gap = (gap - 1) / 3; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];

			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
				array[j] = array[j - gap];

			array[j] = tmp;
		}

		print_array(array, size);
	}
}
