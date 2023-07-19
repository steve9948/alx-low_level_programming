#include "function_pointers.h"

/**
 * int_index - returns the index if comparison is true, else -1
 * @array: array
 * @size: size of elements in array
 * @cmp: pointer to a function of the three functions in main
 *
 * Return: index of matching element, or -1 if no match found
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int a;

	if (array == NULL || size <= 0 || cmp == NULL)
		return (-1);

	for (a = 0; a < size; a++)
	{
		if (cmp(array[a]))
			return (a);
	}

	return (-1);
}
