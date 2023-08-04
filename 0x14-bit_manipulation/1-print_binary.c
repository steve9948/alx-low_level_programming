#include "main.h"

/**
 * print_binary - Prints the binary representation of a decimal number.
 * @n: The number to print in binary.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
	int flag = 0;

	while (mask)
	{
		if (n & mask)
		{
			_putchar('1');
			flag = 1;
		}
		else if (flag || mask == 1)
			_putchar('0');

		mask >>= 1;
	}
}
