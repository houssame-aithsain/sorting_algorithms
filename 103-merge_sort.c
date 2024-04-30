#include "sort.h"

/**
 * merge - Merges two sorted subarrays into a single sorted array
 * @array: Array to be sorted
 * @temp: Temporary array to store the sorted elements
 * @low: Starting index of the partition
 * @mid: Middle index of the partition
 * @high: Ending index of the partition
 */

void merge(int *array, int *temp, int low, int mid, int high)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + low, mid - low + 1);
	printf("[right]: ");
	print_array(array + mid + 1, high - mid);
	for (i = low, j = mid + 1, k = low; i <= mid && j <= high; k++)
	{
		if (array[i] <= array[j])
		{
			temp[k] = array[i];
			i++;
		}
		else
		{
			temp[k] = array[j];
			j++;
		}
	}
	while (i <= mid)
	{
		temp[k] = array[i];
		i++;
		k++;
	}
	while (j <= high)
	{
		temp[k] = array[j];
		j++;
		k++;
	}
	for (i = low; i <= high; i++)
		array[i] = temp[i];
	printf("[Done]: ");
	print_array(array + low, high - low + 1);
}

/**
 * merge_sort_recursive - Recursively sorts an array of integers
 * in ascending order using the Merge sort algorithm
 * @array: Array to be sorted
 * @temp: Temporary array to store the sorted elements
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 */
void merge_sort_recursive(int *array, int *temp, int low, int high)
{
	int mid;

	if (low < high)
	{
		mid = (low + high) / 2;
		merge_sort_recursive(array, temp, low, mid);
		merge_sort_recursive(array, temp, mid + 1, high);
		merge(array, temp, low, mid, high);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;

	merge_sort_recursive(array, temp, 0, size - 1);
	free(temp);
}
