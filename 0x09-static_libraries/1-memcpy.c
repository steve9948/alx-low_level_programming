#include "main.h"
/**
 *_memcpy - Copies memory area
 *@dest: Destination where memory is stored
 *@src: memory which is copied
 *@n: number of bytes
 *
 *Return: copied memory with n bytes value changed
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int a = 0;
	int i = n;

	for (; a < i; a++)
	{
		dest[a] = src[a];
		n--;
	}
	return (dest);
}
