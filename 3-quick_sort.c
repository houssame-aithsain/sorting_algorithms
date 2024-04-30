#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Recursively sorts an array of integers in ascending
 * order using the quick sort algorithm
 *
 * @array: The array to be sorted
 * @low: The index of the first element in the partition
 * @high: The index of the last element in the partition
 * @size: Number of elements in @array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * partition - Partitions an array of integers in ascending order using the
 * Lomuto partition scheme
 *
 * @array: The array to be partitioned
 * @low: The index of the first element in the partition
 * @high: The index of the last element in the partition
 * @size: Number of elements in @array
 *
 * Return: The index of the pivot element
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = low - 1;
	for (j = low; j < high; ++j)
	{
		if (array[j] < pivot)
		{
			++i;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}
