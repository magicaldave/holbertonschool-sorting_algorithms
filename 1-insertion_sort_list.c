#include "sort.h"

/**
 * insertion_sort_list - uses insertion sort method to order numbers
 * @list: list of ints to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *a, *b;

	if (!list || !*list)
		return;

	a = (*list)->next;

	while (a)
	{
		b = a->next;
		while (a->prev && a->n < a->prev->n)
		{
			a->prev->next = a->next;
			if (a->next)
				a->next->prev = a->prev;
			a->next = a->prev;
			if (a->next)
			{
				a->prev = a->next->prev;
				a->next->prev = a;
			}
			if (a->prev)
				a->prev->next = a;
			else
				(*list) = a;
			print_list(*list);
		}
		a = b;
	}
}
