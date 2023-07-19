#include "function_pointers.h"
#include <stdio.h>
/**
 * print_name -Method prints that has pointer to its function
 * @name: string to be add
 * @f: pointer to the function
 * Return: void
 **/
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
