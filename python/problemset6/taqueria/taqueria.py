import sys
menu = {
    "Baja Taco": 4.00,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}
total = 0
print("Welcome to Felipe's Taqueria!")
for i, j in menu.items():
    print(i, "%0.2f" % j, sep=": $")
while True:
    try:
        choice = input("Enter item: ").title()
        if choice in menu:
            total += menu[choice]
            print("Total: $%0.2f" % total)
        else:
            print("Please enter an item that's displayed on the menu!")
            continue
    except EOFError:
        print("\nTotal: $%0.2f" % total)
        print("Have a wonderful meal, see you soon!")
        sys.exit(0)
