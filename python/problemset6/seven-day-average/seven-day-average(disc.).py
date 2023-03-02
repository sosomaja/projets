import csv
import requests
import sys


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    ks = {}
    ms = {}
    for i in reader:
        if ks.get(i['state']) is not None:
            n = int(i['cases']) - int(ks[i['state']])
            ks[i['state']] = n
            if (len(ms[i['state']]) > 14):
                del ms[i['state']][0]
            ms[i['state']].append(n)
        else:
            ks[i['state']] = int(i['cases'])
            ms[i['state']] = [int(i['cases'])]
    return ms


# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    li = []
    for i in states:
        if i in new_cases:
            lweek = sum(new_cases[i][7:])/7
            fweek = sum(new_cases[i][0:7])/7
            n = (lweek-fweek)/lweek
            d = "n increase"
            if n < 0:
                n = round(-n*100)
                d = " decrease"
            else:
                n=round(n*100)
            print(
                f"{i} had a 7-day average of {lweek} and a{d} of {n}%.")


main()
