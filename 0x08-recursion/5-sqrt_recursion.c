#include "main.h"

int actual_sqrt_recursion(int n, int a);

/**
 * _sqrt_recursion - Returns the square root of a number.
 * @n: The number to be square rooted.
 *
 * Return: Result of the square root.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (actual_sqrt_recursion(n, 0));
}

/**
 * actual_sqrt_recursion - Method to find the square root of a number.
 * @n: Number used to find the square root of.
 * @a: Iterator.
 *
 * Return: The resulting square root.
 */
int actual_sqrt_recursion(int n, int a)
{
	if (a * a > n)
		return (-1);
	if (a * a == n)
		return (a);
	return (actual_sqrt_recursion(n, a + 1));
}
