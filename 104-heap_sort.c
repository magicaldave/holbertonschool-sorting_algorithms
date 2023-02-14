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
 * @N: Total length of heap
 */
void heapify(int arr[], int N, int curr_idx)
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
		/* Recursively heapify the affected sub-tree */
		heapify(arr, N, largest);
	}
}

/**
 * heap_sort - function to heapify and sort arrap
 * @arr: array to sort
 * @N: number of elements in array
 */
void heap_sort(int arr[], int N)
{
	int i;
	/* Build max heap */
	for (i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i);
	/* Heap sort */
	for (i = N - 1; i >= 0; i--)
	{
		/* printf("Swapping positions 0 and %d:\n", i); */
		swap(&arr[0], &arr[i]);
		/*
		 * Heapify root element to get highest element at
		 * root again
		 */
		heapify(arr, i, 0);
	}
}
