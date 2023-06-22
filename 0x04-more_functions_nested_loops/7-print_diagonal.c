#include "main.h"

/**
 * print_diagonal - Prints a diagonal line on the terminal
 * @num: Number of times '\' to be printed
 *
 * Return: 0
 */
void print_diagonal(int num)
{
	if (num <= 0)
	{
		_putchar('\n');
	}
	else
	{
		int i, j;

		for (i = 0; i < num; i++)
		{
			for (j = 0; j < num; j++)
			{
				if (j == i)
					_putchar('\\');
				else if (j < i)
					_putchar(' ');
			}
			_putchar('\n');
		}
	}
}
