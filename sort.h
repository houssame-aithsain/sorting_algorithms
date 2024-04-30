#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_recursion(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);
void swap(int *a, int *b);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge_sort_recursion(int *array, int low, int high, size_t size);
void merge(int *array, int low, int mid, int high, size_t size);
void heap_sort(int *array, size_t size);
void heapify(int *array, int n, int i, size_t size);
void radix_sort(int *array, size_t size);
void counting_sort_radix(int *array, size_t size, int exp);
void bitonic_sort(int *array, size_t size);
void bitonic_sort_recursion(int *array, int low,
		int count, int dir, size_t size);
void bitonic_merge(int *array, int low, int count, int dir, size_t size);
void quick_sort_hoare(int *array, size_t size);
void quick_sort_hoare_recursion(int *array, int low, int high, size_t size);
int partition_hoare(int *array, int low, int high, size_t size);
void swap_hoare(int *a, int *b);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void counting_sort_radix(int *array, size_t size, int exp);

#endif /* SORT_H */
