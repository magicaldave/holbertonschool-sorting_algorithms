/* Heap Sort in C */
#include <stdio.h>
#include "sort.h"

/**
 * swap - swaps two int pointer values
 * @a: swappee
 * @b: swappee
 */
void swap(int *a, int *b)
{
	int temp = *a;

	/* printf("swapping %d with %d\n", *a, *b); */
	*a = *b;
	*b = temp;
}

/**
 * heapify - To heapify a subtree rooted with node curr_idx
 * @curr_idx: - largest element provided as arg
 * @arr: array to heapify
 * @arr_size: total size of array to heapify
 * @N: Subsection length
 */
void heapify(int arr[], int N, int curr_idx, size_t arr_size)
{
	/* Find largest among root, left child and right child */

	/* Initialize largest as root */
	int largest = curr_idx;
	/* left = 2*i + 1 */
	int left = 2 * curr_idx + 1;
	/* right = 2*i + 2 */
	int right = 2 * curr_idx + 2;

	/* If left child is larger than root */
	if (left < N && arr[left] > arr[largest])
		largest = left;

	/*
	 * If right child is larger than largest
	 * so far
	 */
	if (right < N && arr[right] > arr[largest])
		largest = right;

	/*
	 * Swap and continue heapifying if root is not largest
	 * If largest is not root
	 */
	if (largest != curr_idx)
	{
		/* printf("Swapping positions %d and %d:\n", curr_idx, largest); */
		swap(&arr[curr_idx], &arr[largest]);
		print_array(arr, arr_size);
		/* Recursively heapify the affected sub-tree */
		heapify(arr, N, largest, arr_size);
	}
}

/**
 * heap_sort - function to heapify and sort arrap
 * @arr: array to sort
 * @size: number of elements in array
 */
void heap_sort(int arr[], size_t size)
{
	int i;
	/* Build max heap */
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(arr, size, i, size);
	/* Heap sort */
	for (i = size - 1; i > 0; i--)
	{
		/* printf("Swapping positions 0 and %d:\n", i); */
		swap(&arr[0], &arr[i]);
		print_array(arr, size);
		/*
		 * Heapify root element to get highest element at
		 * root again
		 */
		heapify(arr, i, 0, size);
	}
}
