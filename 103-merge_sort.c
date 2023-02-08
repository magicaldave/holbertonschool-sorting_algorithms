#include "sort.h"
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void print_array_mt(const int *array, size_t size)
{
    size_t i;
    pthread_mutex_lock(&mutex);
    for (i = 0; i < size; i++)
    {
	    if (i > 0)
		    printf(", ");
	    printf("%d", array[i]);
    }
    printf("\n");
    pthread_mutex_unlock(&mutex);
}
void *merge_sort_thread(void *args)
{
	struct merge_sort_args *ms_args = (struct merge_sort_args *)args;
	int *temp, *array = ms_args->array;
	size_t size = ms_args->size;
	size_t mid = size / 2;
	size_t i = 0, j = mid, k = 0;
	pthread_t left_thread, right_thread;
	struct merge_sort_args left_args;
	struct merge_sort_args right_args;
	left_args.array = array;
	left_args.size = mid;
	right_args.array = array + mid;
	right_args.size = size - mid;

	if (size < 2)
        return (NULL);
	pthread_create(&left_thread, NULL, merge_sort_thread, &left_args);
        pthread_create(&right_thread, NULL, merge_sort_thread, &right_args);
	pthread_join(left_thread, NULL);
	pthread_join(right_thread, NULL);
	printf("Merging...\n");
	printf("[left]: ");
	print_array_mt(array, mid);
	printf("[right]: ");
	print_array_mt(array + mid, size - mid);
	temp = (int *)malloc(size * sizeof(int));
	while (i < mid && j < size)
	{
		if (array[i] < array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	while (i < mid)
		temp[k++] = array[i++];
	while (j < size)
		temp[k++] = array[j++];
	for (i = 0; i < size; i++)
		array[i] = temp[i];
	printf("[Done]: ");
	print_array(array, size);
	free(temp);
	return (NULL);
}

void merge_sort(int *array, size_t size)
{
	struct merge_sort_args args;
	pthread_t thread;

	args.array = array;
	args.size = size;
	pthread_create(&thread, NULL, merge_sort_thread, &args);
	pthread_join(thread, NULL);
}
