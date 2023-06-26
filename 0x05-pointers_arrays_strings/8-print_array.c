#include "main.h"

/**
 * print_array - Prints n elements of an array
 * @a: array name
 * @num: is the number of elements of the array
 * Return: a and num inputs
 */
void print_array(int *a, int num)
{
	int i;

	for (i = 0; i < (num - 1); i++)
	{
		printf("%d, ", a[i]);
	}
		if (i == (num - 1))
		{
			printf("%d", a[num - 1]);
		}
			printf("\n");
}
