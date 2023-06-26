#include "main.h"
/**
 * puts2 - Prints only one character out of two
 * starting with the first one
 * @str: input
 * Return: print
 */
void puts2(char *str)
{
	int i = 0;
	int j = 0;
	char *y = str;
	int k;

	while (*y != '\0')
	{
		y++;
		i++;
	}
	j = i - 1;
	for (k = 0 ; k <= j ; k++)
	{
		if (k % 2 == 0)
	{
		_putchar(str[k]);
	}
	}
	_putchar('\n');
}
