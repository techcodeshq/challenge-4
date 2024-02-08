// olive: copy and paste this into a C replit and run it
// (or compile it with a C compiler if you know how to!)

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <memory.h>

// olive: i've deciphered this constant from what the code does
#define MAX_MESSAGE_LENGTH 64

uint64_t *encrypt(uint64_t a, uint64_t b, char *c)
{
    uint64_t *d = (uint64_t *)malloc(MAX_MESSAGE_LENGTH * sizeof(uint64_t));
    memset(d, 0, MAX_MESSAGE_LENGTH * sizeof(uint64_t));

    for (int i = 0; i < MAX_MESSAGE_LENGTH; i = -~i)
    {
        d[i] = (uint64_t)c[i] * a + b;
        if (i & 1)
        {
            d[i] = (d[i] * b) ^ d[i - 1];
            b = d[i] % 24725;
        }
        else
        {
            a = (d[i] % 251) + 1;
        }
    }

    return d;
}

// olive: the code below is just for allowing you to use the encrypt function

char *getInput()
{
    char *message = (char *)malloc(MAX_MESSAGE_LENGTH * sizeof(char));
    memset(message, 0, MAX_MESSAGE_LENGTH * sizeof(char));

    printf("Enter a message (max %d characters): ", MAX_MESSAGE_LENGTH);
    scanf("%63[^\n]", (char *)message);

    return message;
}

int main()
{
    const int keyOne = 229;
    const int keyTwo = 83;
    char *message = getInput();
    uint64_t *encryptedMessage = encrypt(keyOne, keyTwo, message);

    for (int i = 0; i < MAX_MESSAGE_LENGTH; i++)
    {
        printf("%ld ", encryptedMessage[i]);
    }

    return 0;
}