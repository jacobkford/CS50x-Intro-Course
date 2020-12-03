import csv, sys
from cs50 import SQL

# Establishes the database variable
db = SQL("sqlite:///students.db")

# Checks for correct command line argument usage
if len(sys.argv) != 2:
    print("Usage: python import.py characters.csv")
    sys.exit(1)

# Opens the characters csv file, writing it to a dictionary
with open(sys.argv[1], newline='') as c_file:
    characters = csv.DictReader(c_file)
    for character in characters:
        # We are going to split the characters name up into first, middle & last name
        full_name = character['name'].split()
        # If they don't have a middle name, we're going to add a 'None' value to it instead
        if len(full_name) == 2:
            temp = full_name[1]
            full_name[1] = None
            full_name.append(temp)
        # Imports the character data into the SQL database
        db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                    full_name[0], full_name[1], full_name[2], character['house'], character['birth'])
# Ends program
sys.exit(0)