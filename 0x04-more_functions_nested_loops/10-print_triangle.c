#include "main.h"

/**
 * print_triangle - prints a triangle, followed by a new line
 * @size: size of the triangle
 */
void print_triangle(int size)
{
    if (size <= 0)
    {
        _putchar('\n');
    }
    else
    {
        int row, column;

        for (row = 1; row <= size; row++)
        {
            for (column = 1; column <= row; column++)
            {
                _putchar('#');
            }
            _putchar('\n');
        }
    }
}
