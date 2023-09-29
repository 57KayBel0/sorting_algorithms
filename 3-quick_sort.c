#include "sort.h"

/**
 * swap - swaps two elements in an array
 * @a: first element to swap
 * @b: second element to swap
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - partitions an array using the Lomuto scheme
 * @array: array to partition
 * @low: low index of the partition
 * @high: high index of the partition
 * @size: size of the array
 * Return: index of the pivot after partitioning
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;

			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		if (array[i + 1] > pivot)
		{
			swap(&array[i + 1], &array[high]);
			print_array(array, size);
		}

		}
	}
	return (i + 1);
}
/**
 * quick_sort_rec - sorts an array of integers
 *          in ascending order using recursion
 * @array: array to sort
 * @low: low index of the partition to sort
 * @high: high index of the partition to sort
 * @size: size of the array
 */
void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = lomuto_partition(array, low, high, size);
		quick_sort_rec(array, low, pi - 1, size);
		quick_sort_rec(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in
 *  ascending order using the Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	return;

	quick_sort_rec(array, 0, size - 1, size);
}
