#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending order
 *                     using the Cocktail Shaker Sort algorithm.
 *
 * @list: Pointer to the pointer of the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 0;

	listint_t *current;
	listint_t *tmp;

	if (!list || !(*list) || !((*list)->next))
		return;

	do {
		swapped = 0;
		current = *list;

		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				if (current->prev != NULL)
					current->prev->next = current->next;
				else
					*list = current->next;

				current->next->prev = current->prev;
				tmp = current->next;
				current->next = tmp->next;
				current->prev = tmp;
				tmp->next = current;
				swapped = 1;
				print_list(*list);
			}
			else
			{
					current = current->next;
			}
		}

		if (!swapped)
			break;

		swapped = 0;
		current = current->prev;

		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				if (current->next != NULL)
					current->next->prev = current->prev;

				current->prev->next = current->next;
				tmp = current->prev;
				current->prev = tmp->prev;
				current->next = tmp;
				tmp->prev = current;
				swapped = 1;
				print_list(*list);
			}
			else
			{
					current = current->prev;
			}
		}
	} while (swapped);

}
