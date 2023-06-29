#include "main.h"
/**
 * reverse_array - Reverse an array of integers
 * @a: array
 * @n: number of elements in an array offset
 *
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int j;
	int t;

	for (j = 0; j < n--; j++)
	{
		t = a[j];
		a[j] = a[n];
		a[n] = t;
	}
}
