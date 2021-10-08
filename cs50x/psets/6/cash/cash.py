from cs50 import get_float


def main():
    while True:
        dollars = get_float("Change owed: ")
        if dollars > 0:
            break

    cents = round(dollars * 100)
    nCoins = 0
    coins = [25, 10, 5, 1]

    for coin in coins:
        nCoins += whileCents(cents, coin)
        cents %= coin

    print(f"{nCoins}")


def whileCents(n, m):
    result = 0
    while n >= m:
        n -= m
        result += 1
    return result


main()