#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * _strdup - duplicates to the new memory space location
 * @str: char
 * Return: 0
 */
char *_strdup(char *str)
{
	char *duplicate;
	int i, r = 0;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
		i++;

	duplicate = malloc(sizeof(char) * (i + 1));

	if (duplicate == NULL)
		return (NULL);

	for (r = 0; str[r]; r++)
		duplicate[r] = str[r];

	return (duplicate);
}
