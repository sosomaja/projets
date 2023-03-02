from sys import argv, exit
import random
from pyfiglet import Figlet
figlet = Figlet()
if len(argv) == 1:
    y = figlet.getFonts()
    z = random.choice(y)
    figlet.setFont(font=z)
elif len(argv) == 3:
    if argv[2] in figlet.getFonts():
        figlet.setFont(font=argv[2])
    else:
        print("Invalid usage")
        exit(1)
else:
    print("Invalid usage")
    exit(1)
text = input("Input: ")
print("Output: ")
print(figlet.renderText(text))
