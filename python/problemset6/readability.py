import math
import re


def main():
    index(input("Text: "))


def index(text):
    z = len(re.findall("[A-Za-z]", text))
    n = text.split()
    c = len(n)
    x = len(re.findall("[!?.]", text))
    idx = round(0.0588*((z/c)*100)-0.296*((x/c)*100)-15.8)
    if idx < 1:
        print("Before Grade 1")
    elif idx > 16:
        print("Grade 16+")
    else:
        print(f"Grade {idx}")


main()
