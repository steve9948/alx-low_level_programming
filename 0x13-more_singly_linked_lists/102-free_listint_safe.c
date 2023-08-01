#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list.
 * @h: Pointer to the pointer to the first node in the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current, *temp;
	size_t count = 0;

	if (h == NULL || *h == NULL)
		return (0);

	current = *h;
	while (current)
	{
		count++;
		temp = current->next;
		free(current);
		current = temp;

		if (current == *h)
		{
			*h = NULL;
			break;
		}
	}

	return (count);
}
