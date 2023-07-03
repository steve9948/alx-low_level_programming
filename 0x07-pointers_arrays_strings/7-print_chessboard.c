#include "main.h"
/**
 * print_chessboard - Entry point for the chessboard
 * @a: array of the chess contents
 * Return: Always 0 (Success)
 */
void print_chessboard(char (*a)[8])
{
	int a;
	int j;

	for (a = 0; a < 8; a++)
	{
		for (j = 0; j < 8; j++)
			_putchar(a[a][j]);
		_putchar('\n');
	}
}
