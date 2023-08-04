#include "main.h"

/**
 * print_binary - Prints the binary representation of a decimal number.
 * @num: The number to be printed in binary.
 *
 * Description: This function converts a decimal number to its binary
 *              representation and prints it to the standard output.
 */
void print_binary(unsigned long int num)
{
    int bit_pos, digit_count = 0;
    unsigned long int current;

    for (bit_pos = 63; bit_pos >= 0; bit_pos--)
    {
        current = num >> bit_pos;

        if (current & 1)
        {
            _putchar('1');
            digit_count++;
        }
        else if (digit_count)
        {
            _putchar('0');
        }
    }

    if (!digit_count)
    {
        _putchar('0');
    }
}
