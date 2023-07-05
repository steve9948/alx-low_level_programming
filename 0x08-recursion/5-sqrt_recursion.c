#include "main.h"

int actual_sqrt_recursion(int n, int a);

/**
 * _sqrt_recursion - Method returns the square root of a number
 * @n: The number t be square rooted
 *
 * Return: Result of the square root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (actual_sqrt_recursion(n, 0));
}

/**
 * actual_sqrt_recursion - Recursive method to find the
 * square root of a number
 * @n: number used to find the sqaure root of
 * @i: Iterator
 *
 * Return: the resulting square root
 */
int actual_sqrt_recursion(int n, int a)
{
	if (a * a > n)
		return (-1);
	if (a * a == n)
		return (a);
	return (actual_sqrt_recursion(n, a + 1));
}
