from cs50 import get_int
from sys import exit
from math import floor

# Asks user for input the card value, it will repeat the question if the answer isn't a positive number
card = 0
while (card <= 0):
    card = get_int("Credit Card number: ")

check = card
last = 0
total = 0

while (check > 0):
    # Checks every first digit
    last = check % 10
    total += last

    # Gets rid of right most digit
    check /= 10
    check = floor(check)

    # Checks every second digit
    sec_last = (check % 10) * 2

    # If the number is 2 digits, it will add them both individually to the total
    if (sec_last >= 10):
        total += sec_last % 10
        sec_last /= 10
        total += floor(sec_last)
    else:
        total += sec_last

    # Checks every first digit
    check /= 10
    check = floor(check)

# Counts the amount of digits in the card
digits = card
count = len(str(digits))

# Finds the first digit on the card
first = card
while (first >= 10):
    first /= 10
first = int(first)

# Finds the first two digits on the card
first_two = card
while (first_two >= 100):
    first_two /= 10
first_two = int(first_two)

# Luhn’s algorithm check
if (total % 10 != 0):
    print("INVALID")
    exit(1)

# Check if the card is a VISA card
if (first == 4 and (count == 13 or count == 16)):
    print("VISA")
    exit(0)

# Checks if the card is an American Express card
elif ((first_two == 34 or first_two == 37) and count == 15):
    print("AMEX")
    exit(0)

# Checks if the card is a MasterCard
elif ((50 < first_two and 56 > first_two) and count == 16):
    print("MASTERCARD")
    exit(0)

# Otherwise the card is invalid
else:
    print("INVALID")
    exit(2)
