#include "main.h"
/**
 * _memset - Fills the memory with a specific value
 * @s: Address of memory to be filled
 * @b: The desired value
 * @n: bytes to be changed
 *
 * Return: changed array with new value for n bytes
 */
char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}
