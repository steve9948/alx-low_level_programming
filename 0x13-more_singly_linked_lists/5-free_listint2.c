#include <stdlib.h>
#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list.
 * @head: Pointer to the pointer to the head of the list to be freed.
 */
void free_listint2(listint_t **head)
{
	listint_t *current;

	if (head == NULL)
		return;

	while (*head != NULL)
	{
		current = *head;
		*head = (*head)->next;
		free(current);
	}

	*head = NULL;
}
