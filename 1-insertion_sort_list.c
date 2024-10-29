#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm.
 * @list: Double pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		while (current->prev && current->n < current->prev->n)
		{
			temp = current->prev;
			temp->next = current->next;

			if (current->next)
				current->next->prev = temp;
			current->prev = temp->prev;
			current->next = temp;
			temp->prev = current;

			if (current->prev)
				current->prev->next = current;
			else
				*list = current;
			print_list(*list);
		}
		current = current->next;
	}
}
