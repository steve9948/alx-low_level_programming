#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 8

/**
 * generateRandomChar - Generates a random character
 *
 * Return: A random character
 */
char generateRandomChar() {
    int randomNum = rand() % 62;
    if (randomNum < 26) {
        return 'A' + randomNum;
    } else if (randomNum < 52) {
        return 'a' + (randomNum - 26);
    } else {
        return '0' + (randomNum - 52);
    }
}

/**
 * generateRandomPassword - Generates a random password
 * @password: The buffer to store the generated password
 */
void generateRandomPassword(char* password) {
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = generateRandomChar();
    }
    password[PASSWORD_LENGTH] = '\0';
}

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main() {
    srand(time(NULL));

    char password[PASSWORD_LENGTH + 1];
    generateRandomPassword(password);

    printf("Generated Password: %s\n", password);

    return 0;
}
