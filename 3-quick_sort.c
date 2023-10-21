#include "sort.h"

/**
 * partition - Lomuto's Partition
 * @array: array
 * @low: low
 * @high: high
 * @size: size
 * Return: j + 1
*/

int partition(int *array, int low, int high, size_t size)
{
	int i, j = (low - 1), tmp;
	int pi = array[high];

	for (i = low; i <= high - 1; i++)
	{
		if (array[i] < pi)
		{
			j++;

			if (array[j] != array[i])
			{
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
				print_array(array, size);
			}
		}
	}
	if (array[j + 1] != array[high])
	{
		tmp = array[j + 1];
		array[j + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	return (j + 1);
}

/**
 * quick_ps - quick sort
 * @array: array
 * @low: low
 * @high: high
 * @size: size
*/

void quick_ps(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		quick_ps(array, low, pi - 1, size);
		quick_ps(array, pi + 1, high, size);
	}

}

/**
 * quick_sort - quick sort
 * @array: array
 * @size: size
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;

	quick_ps(array, 0, size - 1, size);
}
