#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must contain alphabetic characters only\n");
            return 1;
        }
        for (int j = 0; j < i; j++)
        {
            if (argv[1][j] == argv[1][i])
            {
                printf("Key must contain each letter exactly once\n");
                return 1;
            }
        }
    }

    string txt = get_string("plaintext:  ");

    for (int i = 0, n = strlen(txt); i < n; i++)
    {
        if (isupper(txt[i]))
        {
            int j = (txt[i] - 65) % 26;
            txt[i] = toupper(argv[1][j]);
        }
        else if (islower(txt[i]))
        {
            int j = (txt[i] - 97) % 26;
            txt[i] = tolower(argv[1][j]);
        }
    }

    printf("ciphertext: %s\n", txt);

    return 0;
}