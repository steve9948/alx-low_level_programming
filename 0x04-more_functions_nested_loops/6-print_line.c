#include "main.h"

/**
 * print_line - outputs a straight line short to longest
 * @num: Number of the character '_' to be printed
 *
 * Return: void
 */
void print_line(int num)
{
	if (num <= 0)
	{
		_putchar('\n');
	}
	else
	{
		int i;

		for (i = 1; i <= num; i++)
		{
			_putchar('_');
		}
		_putchar('\n');
	}
}
