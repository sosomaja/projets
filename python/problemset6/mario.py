def main():
    x = int(input("Enter size of pyramid: "))
    half_pyramid(x)
    print("-------------")
    full_pyramid(x)


def half_pyramid(n):
    for i in range(1, n+1):
        print(" "*(n-i), "#"*i, sep="")


def full_pyramid(n):
    for i in range(1, n+1):
        print(" "*(n-i), "#"*i, "  ", "#"*i, sep="")


main()
