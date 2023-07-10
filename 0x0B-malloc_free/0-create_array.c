#include "main.h"
#include <stdlib.h>
/**
 * create_array - create an array of size (size) and assign char "c"
 * @size: size of the array
 * @c: char to be assigned
 * Description: create array of size size and assign char c
 * Return: pointer to the array, NULL if it fail
 *
 */
char *create_array(unsigned int size, char c)
{
	char *str;
	unsigned int a;

	str = malloc(sizeof(char) * size);
	if (size == 0 || str == NULL)
		return (NULL);

	for (a = 0; a < size; a++)
		str[a] = c;
	return (str);
}
