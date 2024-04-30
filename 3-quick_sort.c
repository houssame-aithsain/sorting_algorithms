#include "sort.h"

/**
 * partition - Lomuto partition scheme
 * @array: Array to be sorted
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the @array
 * Return: The partition index
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = (low - 1);
	int j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	if (i + 1 != high)
		print_array(array, size);

	return (i + 1);
}

/**
 * quick_sort_recursion - Implements the quicksort algorithm through recursion
 * @array: Array to be sorted
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the @array
 */
void quick_sort_recursion(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int partition_index = partition(array, low, high, size);

		quick_sort_recursion(array, low, partition_index - 1, size);
		quick_sort_recursion(array, partition_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * @array: Array to be sorted
 * @size: Size of the @array
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_recursion(array, 0, size - 1, size);
}
