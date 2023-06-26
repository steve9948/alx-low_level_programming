#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 8

/**
 * generateRandomChar - Generates a random character
 *
 * Return: A random character
 */
char generateRandomChar(void)
{
	int randomNum = rand() % 62;

	if (randomNum < 26)
		return 'A' + randomNum;
	else if (randomNum < 52)
		return 'a' + (randomNum - 26);
	else
		return '0' + (randomNum - 52);
}

/**
 * generateRandomPassword - Generates a random password
 * @password: The buffer to store the generated password
 *
 * This function generates a random password of length 8 by calling the
 * generateRandomChar() function and storing the characters in the password
 * buffer.
 */
void generateRandomPassword(char *password)
{
	int i;

	for (i = 0; i < PASSWORD_LENGTH; i++)
		password[i] = generateRandomChar();

	password[i] = '\0';
}

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char password[PASSWORD_LENGTH + 1];

	srand(time(NULL));
	generateRandomPassword(password);

	printf("Generated Password: %s\n", password);

	return 0;
}

