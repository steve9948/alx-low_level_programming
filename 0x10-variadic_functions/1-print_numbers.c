#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_numbers - Prints numbers, followed by a new line.
 * @separator: The string to be printed between numbers.
 * @n: The number of integers to print.
 * @...: Variable number of integers to be printed.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list nums;
	unsigned int offset;

	va_start(nums, n);

	for (offset = 0; offset < n; offset++)
	{
		printf("%d", va_arg(nums, int));

		if (offset != (n - 1) && separator)
			printf("%s", separator);
	}

	printf("\n");

	va_end(nums);
}
