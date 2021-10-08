#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long cardNum;
    do
    {
        cardNum = get_long("Number: ");
    }
    while (cardNum < 0);

    int length = 0;
    int temp, arr[16];
    while (cardNum > 0)
    {
        temp = cardNum % 10;
        arr[length] = temp;

        cardNum /= 10;
        length++;
    }

    int sum, isLegit;
    int multiply = 0;
    int notMultiply = 0;

    for (int i = 0; i < length; i++)
    {
        if (i % 2 == 0)
        {
            notMultiply += arr[i];
        }
        else
        {
            int temp1;
            int temp2;

            temp1 = arr[i] * 2;
            while (temp1 > 0)
            {
                temp2 = temp1 % 10;
                multiply += temp2;
                temp1 /= 10;
            }
        }
    }

    sum = multiply + notMultiply;
    isLegit = sum % 10;

    int one = length - 1;
    int two = length - 2;
    if (isLegit == 0 && length == 15 && arr[one] == 3 && (arr[two] == 4 || arr[two] == 7))
    {
        printf("AMEX\n");
    }
    else if (isLegit == 0 && length == 16 && arr[one] == 5 && (arr[two] <= 5 && arr[two] > 0))
    {
        printf("MASTERCARD\n");
    }
    else if (isLegit == 0 && (length == 13 || length == 16) && arr[one] == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}