#include <stdio.h>
#include <math.h>

/**
 * main - Finds the largest prime factor of the number 612852475143.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    long int num = 612852475143;
    long int max = -1;
    long int num2;

    while (num % 2 == 0)
    {
        max = 2;
        num /= 2;
    }

    for (num2 = 3; num2 <= sqrt(num); num2 += 2)
    {
        while (num % num2 == 0)
        {
            max = num2;
            num /= num2;
        }
    }

    if (num > 2)
        max = num;

    printf("%ld\n", max);

    return (0);
}
