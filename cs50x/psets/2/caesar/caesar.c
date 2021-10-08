#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int k = atoi(argv[1]);

    string txt = get_string("plaintext:  ");

    for (int i = 0, n = strlen(txt); i < n; i++)
    {
        if (isupper(txt[i]))
        {
            txt[i] = (txt[i] + k - 65) % 26 + 65;
        }
        else if (islower(txt[i]))
        {
            txt[i] = (txt[i] + k - 97) % 26 + 97;
        }
    }

    printf("ciphertext: %s\n", txt);

    return 0;
}