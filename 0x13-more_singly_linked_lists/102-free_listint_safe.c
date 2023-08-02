#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list safely.
 * @h: A pointer to the address of the head of the listint_t list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t nodes = 0;
	listint_t *temp;

	if (h == NULL)
		return (0);

	while (*h != NULL)
	{
		nodes++;
		printf("[%p] %d\n", (void *)*h, (*h)->n);

		if (*h > (*h)->next)
		{
			printf("(nil), (nil)\n");
			break;
		}

		temp = *h;
		*h = (*h)->next;
		free(temp);
	}
	*h = NULL;

	return (nodes);
}
