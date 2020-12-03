import csv, sys
from cs50 import SQL

# Checks for correct command line argument usage
if len(sys.argv) != 2:
    print("Usage Example: python roster.py \'House Name\'")
    sys.exit(1)

# Establishes the database variable, then opens & executes a query that lists all the characters from the specified house in alphabetical order.
db = SQL("sqlite:///students.db")
characters = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last", sys.argv[1])

# Prints every characther in the specified house, which will include their full name and birth year.
for character in characters:
    if character['middle'] == None:
        print(f"{character['first']} {character['last']}, born {character['birth']}")
    else:
        print(f"{character['first']} {character['middle']} {character['last']}, born {character['birth']}")