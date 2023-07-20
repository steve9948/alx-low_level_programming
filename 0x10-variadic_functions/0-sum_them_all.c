#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - Returns the sum of its parameters.
 * @n: The number of parameters.
 * @...: Variable number of arguments to calculate the sum.
 *
 * Return: If n is 0, return 0; otherwise, return the sum.
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list ap;
	unsigned int a;
	int sum = 0;

	va_start(ap, n);

	for (a = 0; a < n; a++)
		sum += va_arg(ap, int);

	va_end(ap);

	return (sum);
}
