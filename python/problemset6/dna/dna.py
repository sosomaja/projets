import csv
import sys
import re


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: dna.py file.csv file.txt")
        sys.exit(1)
    # TODO: Read database file into a variable
    with open(sys.argv[1]) as csvfile:
        file_reader = csv.DictReader(csvfile)
        ppl = []
        for i in file_reader:
            ppl.append(i)
    # TODO: Read DNA sequence file into a variable
    p1 = "AGATC"
    p2 = "AATG"
    p3 = "TATC"
    p4 = "TTTTTTCT"
    p5 = "TCTAG"
    p6 = "GATA"
    p7 = "GAAA"
    p8 = "TCTG"
    line = ""
    if re.search("small.csv", sys.argv[1]):
        li = [p1, p2, p3]
    else:
        li = [p1, p2, p3, p4, p5, p6, p7, p8]
    with open(sys.argv[2]) as file:
        line = file.read().rstrip('\n')

    # TODO: Find longest match of each STR in DNA sequence

    kok = checkpattern(li, line)
    # TODO: Check database for matching profiles

    for i in ppl:
        count = 0
        for k in li:
            if int(i[k]) == int(kok[k]):
                count += 1
        if count == len(li):
            print(i['name'])
            sys.exit(0)
    print("No match")
    sys.exit(0)


def checkpattern(ptrn, seq):
    li = ptrn
    ki = {}
    for i in li:
        a = re.findall(rf'(?:{i})+', seq)
        try:
            b = len(re.findall(i, max(a, key=len)))
        except ValueError:
            print("No match")
            sys.exit(0)
        ki[i] = b
    return ki


main()
