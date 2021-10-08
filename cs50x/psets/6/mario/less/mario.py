from cs50 import get_int

while True:
    height = get_int("height: ")
    if 1 <= height <= 8:
        break

for i in range(height):
    print(" " * (height - i - 1), end="")
    print("#" * (i + 1))