#include <stdlib.h>
#include "lists.h"

/**
 * free_list - Frees the linked list
 * @head: list_t list to be freed
 */
void free_list(list_t *head)
{
	list_t *del;

	while (head)
	{
		del = head->next;
		free(head->str);
		free(head);
		head = del;
	}
}
