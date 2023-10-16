#include "main.h"
/**
 * _puts -Prints a string, followed by a new line, to stdout
 * @str: The string to print
 */
void _puts(char *s)
{
	while (*s != '\0')
	{
		_putchar(*s++);
	}
		_putchar('\n');
}
