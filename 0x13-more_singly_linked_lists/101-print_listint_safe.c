#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow = head, *fast = head;
	size_t count = 0;

	/* Floyd's Cycle Detection Algorithm to check for loops */
	while (fast && fast->next)
	{
		count++;
		printf("[%p] %d\n", (void *)slow, slow->n);
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			printf("-> [%p] %d\n", (void *)slow, slow->n);
			exit(98);
		}
	}

	/* If no loop, print the remaining nodes normally */
	while (slow)
	{
		count++;
		printf("[%p] %d\n", (void *)slow, slow->n);
		slow = slow->next;
	}

	return (count);
}
