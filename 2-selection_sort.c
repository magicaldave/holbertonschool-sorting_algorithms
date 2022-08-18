#include "sort.h"
#include "0-bubble_sort.c"
/**
 * selection_sort - uses selection sort algorithm on an array
 * @array: array to sort
 * @size: size of array to sort
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min_index;

	if (!array)
		return;

	/* One by one move boundary of unsorted subarray */

	for (i = 0; i < size - 1; i++)
	{
		/* Find the minimum element in unsorted array */
		min_index = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min_index])
				min_index = j;
		/*Swap the found minimum element with the first element*/
		swap(&array[min_index], &array[i]);
		if (i != min_index)
			print_array(array, size);
	}
}
