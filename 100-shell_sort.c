#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * shell_sort - Sorts an array of integers using the Shell sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	int temp;
	size_t gap = 1, i, j;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}

		print_array(array, size);

		gap = gap / 3;
	}
}
