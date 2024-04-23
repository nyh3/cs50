from cs50 import get_int

# Get height
while True:
    height = get_int("Height: ")
    if height > 0 and height < 9:
        break

# Loop for each height
for i in range(height):
    i += 1
    # Print black space
    print(" " * (height - i), end="")
    # Print #
    print("#" * i)
