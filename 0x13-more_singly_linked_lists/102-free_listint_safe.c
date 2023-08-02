#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a linked list safely.
 * @head: A pointer to the pointer of the first node in the list.
 *
 * Return: The number of elements in the freed list.
 */
size_t free_listint_safe(listint_t **head)
{
	size_t nodes = 0;
	listint_t *current, *temp;

	if (head == NULL || *head == NULL)
		return (0);

	current = *head;
	while (current)
	{
		temp = current->next;
		nodes++;

		if (current > current->next)
		{
			free(current);
			break;
		}

		free(current);
		current = temp;
	}

	*head = NULL;

	return (nodes);
}
