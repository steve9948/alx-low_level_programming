#include <stdio.h>
#include <math.h>

/**
 * main - finds the largest prime factor in the number 612852475143
 * "/n"shows followed  by a new line 
 * Return: Always 0 (Success)
 */
int main(void)
{
	long int num;
	long int max;
	long int num2;

	num = 612852475143;
	max = -1;

	while (num % 2 == 0)
	{
		max = 2;
		num /= 2;
	}

	for (num2 = 3; num2 <= sqrt(num); num2 = num2 + 2)
	{
		while (num % num2 == 0)
		{
			max = num2;
			num = num / num2;
		}
	}

	if (num > 2)
		max = num;

	printf("%ld\n", max);

	return (0);
}
