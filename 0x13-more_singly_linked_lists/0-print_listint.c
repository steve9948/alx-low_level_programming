#include "lists.h"

/**
 * print_listint - Prints all the elements of a linked list.
 * @h: A pointer to the head of the linked list.
 *
 * Return: The number of nodes in the linked list.
 */
size_t print_listint(const listint_t *h)
{
	size_t num = 0;
	const listint_t *current = h;

	while (current)
	{
		printf("%d\n", current->n);
		num++;
		current = current->next;
	}

	return (num);
}
