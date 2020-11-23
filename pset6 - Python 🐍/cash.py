from cs50 import get_float

# Asks user for input the change value, it will repeat the question if the answer isn't a positive number
dollars = 0
while dollars <= 0:
    dollars = get_float("Change owed: ")

# Converting currency from Dollars to Cents
cents = round(dollars * 100)
coins = 0

# Counts through the coins until the change owed is equal to 0
while cents > 0:
    # Quarter
    if cents >= 25:
        cents -= 25
        coins += 1
    # Dime
    elif cents >= 10:
        cents -= 10
        coins += 1
    # Nickel
    elif cents >= 5:
        cents -= 5
        coins += 1
    else:
    # Penny
        cents -= 1
        coins += 1

# Returns a value equal to the amount of change returned.
print(f"You are owed {coins} coins in total.")
