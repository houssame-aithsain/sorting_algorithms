#include "sort.h"

/**
 * count_arr_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @count: Array to store the count of each element
 * @array: Array to be sorted
 * @output: Array to store the sorted elements
 * @s: Struct to store the size, max and index
 */
void count_arr_sort(int *count, int *array, int *output, count_t s)
{

	for (s.i = 0; s.i <= s.max; s.i++)
		count[s.i] = 0;

	for (s.i = 0; s.i < s.size; s.i++)
		count[array[s.i]]++;

	for (s.i = 1; s.i <= s.max; s.i++)
		count[s.i] += count[s.i - 1];

	print_array(count, s.max + 1);

	for (s.i = 0; s.i < s.size; s.i++)
	{
		output[count[array[s.i]] - 1] = array[s.i];
		count[array[s.i]]--;
	}

	for (s.i = 0; s.i < s.size; s.i++)
		array[s.i] = output[s.i];
}

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output;
	size_t i, max = 0;
	count_t s;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		if (array[i] > (int)max)
			max = array[i];
	}

	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;

	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(count);
		return;
	}

	s.size = size;
	s.max = max;
	s.i = i;
	count_arr_sort(count, array, output, s);

	free(count);
	free(output);
}
