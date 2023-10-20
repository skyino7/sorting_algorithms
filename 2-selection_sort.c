#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: array
 * @size: size
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int tmp, pos;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		pos = 0;

		for (j = i + 1; j < size; ++j)
		{
			if (array[j] < array[min])
			{
				min = j;
				pos = 1;
			}
		}

		if (pos)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
