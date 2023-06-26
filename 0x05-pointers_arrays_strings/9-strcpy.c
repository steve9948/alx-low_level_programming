#include "main.h"

/**
 * char *_strcpy - Prints the string pointed to by src
 * @source: copy to
 * @src: copy from
 * Return: string copied
 */
char *_strcpy(char *source, char *src)
{
	int l = 0;
	int x = 0;

	while (*(src + l) != '\0')
	{
		l++;
	}
	for ( ; x < l ; x++)
	{
		source[x] = src[x];
	}
	source[l] = '\0';
	return (source);
}
