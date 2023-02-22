#ifndef SORT_H
#define SORT_H
/*Standard Library*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
/*Data Structures*/
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
/**
 * struct merge_sort_args - function arguments for merge_sort mt version
 *
 * @array: Array to be sorted by merge_sort
 * @size: Size of the array to be sorted
 */
struct merge_sort_args
{
	int *array;
	size_t size;
};
/*Provided Functions*/
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
/*Function Declarations*/
/*0-bubble_sort.c*/
void bubble_sort(int *array, size_t size);
void swap(int *a, int *b);
/*1-insertion_sort_list.c*/
void insertion_sort_list(listint_t **list);
/*2-selection_sort.c*/
void selection_sort(int *array, size_t size);
/*3-quick_sort.c*/
void quick_sort(int *array, size_t size);
void quickSort(int *array, int low, int high, size_t size);
int partition(int *array, int start, int end, size_t size);
void merge_sort(int *array, size_t size);
/* 103-merge_sort.c */
void merge_sort(int *array, size_t size);
void mergeSortWrap(int *arr, int *temp, size_t size);
void merge(int *l, size_t size_l, int *r, size_t size_r, int *tmp);
/* 104-heap_sort.c */
void heapify(int arr[], int N, int curr_idx, size_t arr_size);
void heap_sort(int arr[], size_t size);
/* 105-radix_sort.c */
void radix_sort(int *array, size_t size);
int max_int(int *array, size_t n);
#endif
