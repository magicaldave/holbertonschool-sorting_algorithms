#include "sort.h"

/**
 * max_int - Finds the largest number in an array of integers
 * @arr: The array to search through
 * @n: The number of digits of the array (to look through on the left side)
 * Return: The largest number from the array
*/

int max_int(int *array, size_t n)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < n; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * radix_sort - Sorting using place values from least significant digit
 * @arr: The array to sort
 * @n: the number of digits of the array (to sort on the left side)
 * Return: void
*/

void radix_sort(int *array, size_t size)
{
	int digits = 0, i, j, max, num, pow;
	int count[10];
	int *new_array;

	if (!array || size < 2)
		return;
	max = max_int(array, size);
	while (max > 0)
	{
		digits++;
		max /= 10;
	}
	pow = 1;
	for (i = 0; i < digits; i++)
	{
		new_array = malloc(sizeof(int) * size);
		for (j = 0; j < 10; j++)
			count[j] = 0;
		for (j = 0; (size_t) j < size; j++)
		{
			num = (array[j] / pow) % 10;
			count[num]++;
		}
		for (j = 1; j < 10; j++)
			count[j] += count[j - 1];
		for (j = size - 1; j >= 0; j--)
		{
			num = (array[j] / pow) % 10;
			new_array[count[num] - 1] = array[j];
			count[num]--;
		}
                for (j = 0; (size_t) j < size; j++)
                        array[j] = new_array[j];
		pow *= 10;
		free(new_array);
		print_array(array, size);
	}
}
