#include "lists.h"

/**
 * listint_len - Returns the number of elements in a linked list.
 * @h: A pointer to the head of the linked list.
 *
 * Return: The number of elements in the linked list.
 */
size_t listint_len(const listint_t *h)
{
	size_t num = 0;
	const listint_t *current = h;

	while (current != NULL)
	{
		num++;
		current = current->next;
	}

	return (num);
}
