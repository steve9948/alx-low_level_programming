#include <stdlib.h>
#include "main.h"

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: Pointer to the memory previously allocated by malloc.
 * @prev: Size of the allocated memory block for ptr.
 * @after: New size of the memory block.
 *
 * Return: Pointer to the newly allocated memory block.
 */
void *_realloc(void *ptr, unsigned int prev, unsigned int after)
{
	char *ptr1, *ptr2;
	unsigned int i;

	if (after == prev)
		return (ptr);

	if (after == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	if (!ptr)
		return (malloc(after));

	ptr1 = malloc(after);
	if (!ptr1)
		return (NULL);

	ptr2 = ptr;

	for (i = 0; i < prev && i < after; i++)
		ptr1[i] = ptr2[i];

	free(ptr);
	return (ptr1);
}
