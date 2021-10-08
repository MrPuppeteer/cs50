from cs50 import get_string


def main():
    cc = get_string("Number: ")

    if isLegit(cc):
        check_type(cc)
    else:
        print("INVALID")


def isLegit(num):
    sum = 0
    for i, m in enumerate(reversed(num)):
        m = int(m)
        if i % 2 == 0:
            sum += m
        else:
            for j in str(m * 2):
                sum += int(j)

    if sum % 10 == 0:
        return True
    else:
        return False


def check_type(cc):
    # get first 2 digit with slicing
    first2 = int(cc[0:2])
    length = len(cc)

    if (first2 == 34 or first2 == 37) and length == 15:
        print("AMEX")
    elif 50 < first2 <= 55 and length == 16:
        print("MASTERCARD")
    elif 40 <= first2 < 50 and (length == 13 or length == 16):
        print("VISA")
    else:
        print("INVALID")


if __name__ == "__main__":
    main()