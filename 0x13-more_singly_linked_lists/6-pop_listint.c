#include "lists.h"

/**
 * pop_listint - Deletes the head node of a linked list.
 * @head: Pointer to the pointer to the first element in the linked list.
 *
 * Return: The data of the deleted element, or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
	if (!head || !*head)
		return (0);

	listint_t *temp = (*head)->next;
	int num = (*head)->n;
	free(*head);
	*head = temp;

	return (num);
}
