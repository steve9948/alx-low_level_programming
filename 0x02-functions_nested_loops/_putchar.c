#include "main.h"
#include <unistd.h>
/**
 * _putchar - writes  c to stdout standard output
 * @c: The  printed character
 *
 * Return:when successful 1.
 * On error, -1 is the returned value, and errno is set as neeeded.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
