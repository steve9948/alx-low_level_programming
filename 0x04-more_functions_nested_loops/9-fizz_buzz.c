#include "main.h"
#include <stdio.h>

/**
 * main - Prints the numbers from 1 to 100, with replacements for Fiz, Buzz and FizzBuzz dependent on its multiplicate
 *
 * Return: 0
 */
int main(void)
{
	int num;

	for (num = 1; num <= 100; num++)
	{
		if (num % 3 == 0 && num % 5 != 0)
		{
			printf("Fizz ");
		}
		else if (num % 5 == 0 && num % 3 != 0)
		{
			printf("Buzz ");
		}
		else if (num % 3 == 0 && num % 5 == 0)
		{
			printf("FizzBuzz ");
		}
		else if (num == 1)
		{
			printf("%d", num);
		}
		else
		{
			printf("%d ", num);
		}
	}

	printf("\n");

	return (0);
}
