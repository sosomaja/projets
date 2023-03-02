import re


def main():
    validate(input("Enter card number: "))


def validate(card):
    sum = 0
    if (len(card) % 2 != 0):
        sum += int(card[0])
    for i in range(len(card)-2, -1, -2):
        x = int(card[i])*2
        while x != 0:
            sum += int(x % 10)
            x /= 10
        sum += int(card[i+1])
    if sum % 10 == 0:
        if re.match("^3[47]", card):
            print("AMEX")
        elif re.match("^5[12345]", card):
            print("MASTERCARD")
        elif re.match("^4", card):
            print("VISA")
    else:
        print("INVALID")


main()
