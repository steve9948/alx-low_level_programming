
#include "main.h"
/**
 * _strlen_recursion - Method that returns the length of a string.
 * @s: The string to be measured.
 *
 * Return: The length of the string masured.
 */
int _strlen_recursion(char *s)
{
	int num = 0;

	if (*s)
	{
		num++;
		num += _strlen_recursion(s + 1);
	}

	return (num);
}
