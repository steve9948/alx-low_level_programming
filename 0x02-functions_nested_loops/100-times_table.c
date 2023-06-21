#include "main.h"

/**
 * print_times_table - Prints the n times table, starting with 0
 * @n: Number of the times table
 */
void print_times_table(int n)
{
	if (n >= 0 && n <= 15)
	{
		int i, j;
		for (i = 0; i <= n; i++)
		{
			print_times_row(i, n);
			_putchar('\n');
		}
	}
}

/**
 * print_times_row - Prints a row of the times table
 * @row: Row number
 * @n: Number of the times table
 */
void print_times_row(int row, int n)
{
	int j, k;

	for (j = 0; j <= n; j++)
	{
		k = j * row;
		if (j != 0)
		{
			_putchar(',');
			_putchar(' ');
			if (k < 10)
			{
				_putchar(' ');
				_putchar(' ');
			}
			else if (k < 100)
			{
				_putchar(' ');
			}
		}
		_putchar(k + '0');
	}
}

