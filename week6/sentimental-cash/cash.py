from cs50 import get_float

# Get change owed
while True:
    change = get_float("Change owed: ")
    if change > 0:
        break

# Change change to integer
change = round(change * 100)
coins = 0

while change > 0:
    # Number of quarters
    if change >= 25:
        change -= 25
        coins += 1

    # Number of dimes
    elif change >= 10:
        change -= 10
        coins += 1

    # Number of nickels
    elif change >= 5:
        change -= 5
        coins += 1

    # Number of pennies
    elif change >= 1:
        change -= 1
        coins += 1

# Print total coins in integer
print(int(coins))
