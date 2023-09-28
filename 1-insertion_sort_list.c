#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using the Insertion sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	return;

	current = (*list)->next;
	while (current != NULL)
	{
		next = current->next;
		prev = current->prev;
		while (prev != NULL && current->n < prev->n)
		{
			/* Swap the nodes */
			prev->next = next;
			if (next != NULL)
			next->prev = prev;
			current->prev = prev->prev;
			current->next = prev;
			if (prev->prev != NULL)
			prev->prev->next = current;
			else
				*list = current;
			prev->prev = current;

			/* Print the list after each swap */
			print_list(*list);

			/* Update the pointers */
			next = current->next;
			prev = current->prev;
		}
		current = next;
	}
}
