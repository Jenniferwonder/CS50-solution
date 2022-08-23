from cs50 import get_int

# Get the right input from the user
while True:
    try:
        height = int(input("Height: "))
        if height > 0 and height < 9:
            break
    except ValueError:
        print("That's not an integer!")

# Print row by row
for row in range(1, height+1):
    lefthash = 0
    righthash = 0
    # Print space for each row
    for space in range(1, height-row+1):
        print(" ", end="")
        space += 1

    # Print lefthash for each row
    while lefthash != row:
        print("#", end="")
        lefthash += 1

    # Print gap between lefthash and righthash
        if lefthash == row:
            print("  ", end="")

    # Print righthash for each row
    while righthash != row:
        print("#", end="")
        righthash += 1

    # Move to the next row
    print()
    row += 1