#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 15
#define EXPECTED_PASSWORD "Tada! Congrats"

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

void generateRandomPassword(char *password)
{
    int i;

    for (i = 0; i < PASSWORD_LENGTH; i++)
        password[i] = generateRandomChar();

    password[i] = '\0';
}

int main(void)
{
    char password[PASSWORD_LENGTH + 1];

    srand(time(NULL));
    generateRandomPassword(password);

    printf("%s\n", password);

    if (strncmp(password, EXPECTED_PASSWORD, PASSWORD_LENGTH) == 0)
        printf("Tada! Congrats\n");
    else
        printf("Wrong password\n");

    return 0;
}
