#include "main.h"

/**
 * print_square - Prints a square, in a new line
 * @value: Size of the square
 *
 * Return: 0
 */
void print_square(int value)
{
	if (value <= 0)
	{
		_putchar('\n');
	}
	else
	{
		int i, j;

		for (i = 0; i < value; i++)
		{
			for (j = 0; j < value; j++)
			{
				_putchar('#');
			}
			_putchar('\n');
		}
	}
}
