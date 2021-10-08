import sys
import csv


def main():
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    data = []
    STRs = []
    max_counts = []
    with open(sys.argv[1]) as csvfile:
        reader = csv.DictReader(csvfile)
        STRs = reader.fieldnames[1:]
        for people in reader:
            data.append(people)

    with open(sys.argv[2]) as txtfile:
        sequence = txtfile.read()

    for i, STR in enumerate(STRs):
        max_counts.append(0)
        for j in range(len(sequence)):
            repeats = 0
            if sequence[j:(j + len(STR))] == STR:
                k = 0
                while sequence[(j + k):(j + k + len(STR))] == STR:
                    repeats += 1
                    k += len(STR)
                if repeats > max_counts[i]:
                    max_counts[i] = repeats

    for i in range(len(data)):
        matches = 0
        for j, STR in enumerate(STRs):
            if int(max_counts[j]) == int(data[i][STR]):
                matches += 1
        if matches == len(STRs):
            print(data[i]['name'])
            sys.exit(0)

    print("No match")
    sys.exit(1)


if __name__ == "__main__":
    main()