#include "main.h"

/**
 * print_number - Prints numbers chars
 * @n: int params
 * Return: 0
 */

void print_number(int i)
{
	unsigned int n1;

	n1 = i;

	if (i < 0)
	{
		_putchar('-');
		n1 = -i;
	}

	if (n1 / 10 != 0)
	{
		print_number(n1 / 10);
	}
	_putchar((n1 % 10) + '0');
}
