#include "main.h"

int actual_prime(int num, int i);

/**
 * is_prime_number - Evaluates a number if it is a prime number or not.
 * @num: Number to be evaluated.
 *
 * Return: 1 if number (num) is a prime number, 0 if not.
 */
int is_prime_number(int num)
{
	if (num <= 1)
		return (0);
	return (actual_prime(num, num - 1));
}

/**
 * actual_prime - Method to calculate number is prime recursively.
 * @num: Number to evaluate.
 * @i: Iterator.
 *
 * Return: 1 if num is prime, 0 if not.
 */
int actual_prime(int num, int i)
{
	if (i == 1)
		return (1);
	if (num % i == 0 && i > 0)
		return (0);
	return (actual_prime(num, i - 1));
}
