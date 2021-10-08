#include <stdio.h>
#include <math.h>
#include <cs50.h>

int whileCents(int n, int m);

int main(void)
{
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);

    int cents = round(dollars * 100);
    int nCoins = 0;
    int coins[4] = {25, 10, 5, 1};

    for (int i = 0; i < 4; i++)
    {
        nCoins += whileCents(cents, coins[i]);
        cents %= coins[i];
    }

    printf("%i\n", nCoins);
}

int whileCents(int n, int m)
{
    int result = 0;
    while (n >= m)
    {
        n -= m;
        result++;
    }
    return result;
}