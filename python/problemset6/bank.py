import sys


def main():
    n = input("Enter a greeting: ")
    n = n.lstrip().lower()
    bank(n)
    sys.exit(0)


def bank(phrase):
    if phrase == "hello":
        print("$0")
    elif phrase[0] == "h":
        print("$20")
    else:
        print('$100')


main()
