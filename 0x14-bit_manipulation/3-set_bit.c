#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index.
 * @n: Pointer to the number whose bit to set.
 * @index: The index of the bit to set, starting from 0 (LSB).
 *
 * Return: 1 if successful, or -1 on error.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	*n = (*n) | (1UL << index);
	return (1);
}
