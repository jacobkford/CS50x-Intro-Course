from cs50 import get_int

# Asks user for input the height value, it will repeat until answer is between numbers 1 - 8
h = 0
while (h > 8 or h < 1):
    h = get_int("Height: ")

# Prints the pyramid of #'s
for i in range(1, h + 1):
    print(" " * (h - i), end="")
    print("#" * i, end="  ")
    print("#" * i)
