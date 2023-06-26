#include "main.h"
/**
 * swap_int - swaps the values of two integers
 * @i: integer to swap
 * @j: integer to swap
 */
void swap_int(int *i, int *j)
{
	int k;

	k = *i;
	*i = *j;
	*j = k;
}
