#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: Pointer to a string of 0 and 1 characters.
 * Return: The converted number, or 0 if invalid input.
 */
unsigned int binary_to_uint(const char *b)
{
    unsigned int result = 0;
    int idx = 0;

    if (b == NULL)
        return 0;

    while (b[idx] != '\0')
    {
        if (b[idx] == '0' || b[idx] == '1')
        {
            result = (result << 1) + (b[idx] - '0');
            idx++;
        }
        else
        {
            return 0; /* Return 0 if invalid input */
        }
    }

    return result;
}

