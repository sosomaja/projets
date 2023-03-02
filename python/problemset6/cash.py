import math


def main():
    n = 0
    while True:
        try:
            n = float(input("Change owed: "))
            if n < 0:
                continue
            break
        except ValueError:
            continue
    c = 0
    while n > 0:
        if n >= 0.25:
            n -= 0.25
        elif n >= 0.10:
            n -= 0.10
        elif n >= 0.05:
            n -= 0.05
        else:
            n -= 0.01
        n = round(n, 3)
        c += 1
    print(c)


main()
