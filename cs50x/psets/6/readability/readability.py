from cs50 import get_string


def main():
    text = get_string("Text: ")

    result = count(text)

    index = calculate(result["letters"], result["words"],
                      result["sentences"])
    printOut(index)


def count(text):
    letters, words, sentences = 0, 1, 0

    for i in text:
        if "a" <= i <= "z" or "A" <= i <= "Z":
            letters += 1
        elif i == " ":
            words += 1
        elif i == "." or i == "!" or i == "?":
            sentences += 1

    result = {"letters": letters, "words": words,
              "sentences": sentences}

    # print(letters, words, sentences)
    return result


def calculate(letters, words, sentences):
    L = (letters / words) * 100
    S = (sentences / words) * 100

    index = round(0.0588 * L - 0.296 * S - 15.8)
    return index


def printOut(index):
    if 0 < index <= 16:
        print(f"Grade {index}")
    elif index <= 0:
        print("Before Grade 1")
    else:
        print("Grade 16+")


if __name__ == "__main__":
    main()