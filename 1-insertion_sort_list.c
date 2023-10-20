#include "sort.h"

/**
 * insertion_sort_list - doubly linked list of integers in ascending order
 * @list: list of elements
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *curr = NULL, *next = NULL, *prev = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;

	while (curr != NULL)
	{
		next = curr->next;
		prev = curr->prev;

		while (prev != NULL && prev->n > curr->n)
		{
			prev->next = curr->next;

			if (curr->next != NULL)
				curr->next->prev = prev;

			curr->next = prev;
			curr->prev = prev->prev;

			if (prev->prev != NULL)
				prev->prev->next = curr;
			else
				*list = curr;

			prev->prev = curr;
			prev = curr->prev;

			print_list(*list);
		}
		curr = next;
	}

}
