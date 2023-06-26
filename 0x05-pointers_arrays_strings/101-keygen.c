#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 8

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

void generateRandomPassword(char* password) {
    int i;
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = generateRandomChar();
    }
    password[PASSWORD_LENGTH] = '\0';
}

int main() {
    srand(time(NULL));

    char password[PASSWORD_LENGTH + 1];
    generateRandomPassword(password);

    printf("Generated Password: %s\n", password);

    return 0;
}
