#include "sort.h"
#include "0-bubble_sort.c"

/**
 * quick_sort - sorts an array using quicksort algo
 * @array: array to sort
 * @size: number of @array elements
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quickSort(array, 0, size - 1, size);
}
/**
 * quickSort - actually does the work of quicksorting
 * @array: data to be sorted
 * @high: highest index to sort
 * @low: lowest index to sort
 * @size: total size of @array
 */
void quickSort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quickSort(array, low, pivot - 1, size);
		quickSort(array, pivot + 1, high, size);
	}
}
/**
 * partition - splits array Lomuto style
 * @array: array to sort
 * @start: first index to be sorted
 * @end: end index to sort
 * @size: total size of @array
 * Return: index of partition
 */
int partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end], index = start, i = 0;

	for (i = start; i < end; i++)
		if (array[i] <= pivot)
		{
			if (index != i)
			{
				swap(&array[i], &array[index]);
				print_array(array, size);
			}
			index++;
		}
	if (index != end)
	{
		swap(&array[end], &array[index]);
		print_array(array, size);
	}
	return (index);
}
