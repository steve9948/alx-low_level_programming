#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_strings - Prints strings, followed by a new line.
 * @separator: The string to be printed between strings.
 * @n: The number of strings to print.
 * @...: Variable number of strings to be printed.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list strings;
	char *str;
	unsigned int offset;

	va_start(strings, n);

	for (offset = 0; offset < n; offset++)
	{
		str = va_arg(strings, char *);

		printf("%s", (str == NULL) ? "(nil)" : str);

		if (offset != (n - 1) && separator)
			printf("%s", separator);
	}

	printf("\n");

	va_end(strings);
}
