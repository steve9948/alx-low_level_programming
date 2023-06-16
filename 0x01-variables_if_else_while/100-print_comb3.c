
#include <stdio.h>

/**
 * main - prints all possible different combinations of two digits
 * Return: ALways 0 (Success)
 */
int main(void)
{
	int num, max;

	for (num = 48; num <= 56; num++)
	{
		for (max = 49; max <= 57; max++)
		{
			if (max > num)
			{
				putchar(num);
				putchar(max);
				if (num != 56 || max != 57)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}

