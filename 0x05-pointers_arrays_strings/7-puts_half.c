#include "main.h"
/**
 * puts_half - Prints half of a string
 * if odd len, j = (length_of_the_string - 1) / 2
 * @str: input
 * Return: half of string
 */
void puts_half(char *str)
{
	int i, j, k;

	k = 0;

	for (i = 0; str[i] != '\0'; i++)
		k++;

	n = (k / 2);

	if ((k % 2) == 1)
		j = ((k + 1) / 2);

	for (i = j; str[i] != '\0'; i++)
		_putchar(str[i]);
	_putchar('\n');
}
