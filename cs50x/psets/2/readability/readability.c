#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cs50.h>

int main()
{
    string text = get_string("Text: ");
    int letters = 0, words = 1, sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] > 64 && text[i] < 91) || (text[i] > 96 && text[i] < 123))
        {
            letters += 1;
        }
        else if (text[i] == 32)
        {
            words += 1;
        }
        else if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences += 1;
        }
    }

    // printf("%i letter(s)\n", letters);
    // printf("%i word(s)\n", words);
    // printf("%i sentence(s)\n", sentences);

    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index > 0 && index <= 16)
    {
        printf("Grade %i\n", index);
    }
    else if (index <= 0)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }

    return 0;
}