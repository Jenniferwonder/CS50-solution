from cs50 import get_float

# Define main function


def main():
    # Ask how many cents the customer is owed
    dollars = get_dollars()

    # Calculate the number of quarters to give the customer
    quarters = calculate_quarters(dollars)
    dollars = round(dollars - quarters * 0.25, 2)

    # Calculate the number of dimes to give the customer
    dimes = calculate_dimes(dollars)
    dollars = round(dollars - dimes * 0.10, 2)

    # Calculate the number of nickels to give the customer
    nickels = calculate_nickels(dollars)
    dollars = round(dollars - nickels * 0.05, 2)

    # Calculate the number of pennies to give the customer
    pennies = calculate_pennies(dollars)
    dollars = round(dollars - pennies * 0.01, 2)

    # Sum coins
    coins = quarters + dimes + nickels + pennies

    # Print total number of coins to give the customer
    print(f"{coins}")

# Get the value of dollars from the user


def get_dollars():

    # To ensure the input value is valid
    while True:
        dollars = get_float("Change owed: ")
        if dollars >= 0:
            break
    return dollars

# Calculate the number of quarters to give the customer


def calculate_quarters(dollars):
    quarters = 0
    while (dollars >= 0.25):
        dollars = round(dollars - 0.25, 2)
        quarters += 1
    return quarters

# Calculate the number of dimes to give the customer


def calculate_dimes(dollars):
    dimes = 0
    while (dollars >= 0.10):
        dollars = round(dollars - 0.10, 2)
        dimes += 1
    return dimes

# Calculate the number of nickles to give the customer


def calculate_nickels(dollars):
    nickels = 0
    while (dollars >= 0.05):
        dollars = round(dollars - 0.05, 2)
        nickels += 1
    return nickels

# Calculate the number of pennies to give the customer


def calculate_pennies(dollars):
    pennis = 0
    while (dollars >= 0.01):
        dollars = round(dollars - 0.01, 2)
        pennis += 1
    return pennis

# Run main function in the correct order


main()

