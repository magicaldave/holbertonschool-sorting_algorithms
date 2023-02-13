#include "sort.h"
#include <stdio.h>
/* Standard top-down implementation. */
/**
 * merge - actually merges the arrays together
 *
 * @l: Left half of array
 * @size_l: Length of left half
 * @r: Right half of array
 * @size_r: Length of right half
 * @tmp: Temporary pointer to store data
 */
void merge(int *l, size_t size_l, int *r, size_t size_r, int *tmp)
{
size_t i = 0, j = 0, k = 0;

	for (i = 0; i < size_l; i++)
		tmp[i] = l[i];

	printf("Merging...\n");
	printf("[left]: ");
	print_array(l, size_l);
	printf("[right]: ");
	print_array(r, size_r);

	for (i = 0; i < size_l && j < size_r; l[k++] = tmp[i], i++)
		for (; j < size_r && r[j] < tmp[i]; j++)
			l[k++] = r[j];

	for (; i < size_l; i++)
		l[k++] = tmp[i];

	for (; j < size_r; j++)
		l[k++] = r[j];

	printf("[Done]: ");
	print_array(l, size_l + size_r);
}
/**
 * mergeSortWrap - Wrapper function to recursively call sort function
 * @temp: temporary pointer to overwrite
 * @arr: Array to be sorted by merge_sort
 * @size: Size of the array to be sorted
 */
void mergeSortWrap(int arr[], int *temp, size_t size)
{
	size_t midpoint;

	if (size < 2)
		return;
	midpoint = size / 2;

	mergeSortWrap(arr, temp, midpoint);
	mergeSortWrap(arr + midpoint, temp + midpoint, size - midpoint);

	merge(arr, midpoint, arr + midpoint, size - midpoint, temp);
}
/**
 * merge_sort - handles memory allocation and invokes wrapper function
 * @array: Array to be sorted by merge_sort
 * @size: Size of the array to be sorted
 */
void merge_sort(int *array, size_t size)
{
	/* Allocate for a size number of integers */
	int *temp = malloc(sizeof(int) * size);

	if (!temp)
		return;
	mergeSortWrap(array, temp, size);
	free(temp);
}
