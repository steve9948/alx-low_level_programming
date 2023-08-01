#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes node at a given index in a linked list.
 * @head: Pointer to the pointer to the first node in the list.
 * @index: Index of the node to delete (starting from 0).
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *temp;
	unsigned int count = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	current = *head;
	while (current != NULL)
	{
		if (count == index - 1)
		{
			if (current->next == NULL)
				return (-1);

			temp = current->next;
			current->next = temp->next;
			free(temp);
			return (1);
		}

		current = current->next;
		count++;
	}

	return (-1);
}
