#include "sort.h"
/**
 *insertion_sort_list - t sorts a doubly linked list of integers
 *in ascending order using the Insertion sort algorithm
 *@list: a pointer to the pointer of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *current;

	temp = (*list)->next;

	while (temp)
	{
		current = temp;
		while (current && current->prev && current->n < current->prev->n)
		{
			if (current->prev->prev)
				current->prev->prev->next = current;
			if (current->next)
				current->next->prev = current->prev;
			current->prev->next = current->next;
			current->next = current->prev;
			current->prev = current->prev->prev;
			current->next->prev = current;
			if (!current->prev)
				*list = current;
			print_list(*list);
		}
		temp = temp->next;
	}
}
