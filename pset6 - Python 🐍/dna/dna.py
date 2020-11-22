import sys, csv, os.path

# Checking if command line argument wasn't inputted correctly
if len(sys.argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    sys.exit(1)

# Creating argument variables for usage checks
database_file = str(sys.argv[1])
sequences_file = str(sys.argv[2])

# If the file inputted first doesn't end with .csv
if not os.path.isfile(database_file) or database_file[-4:] != ".csv":
    print(f"Error: Expected .cvs file, received {database_file[-4:]} file")
    sys.exit(2)
    
# If the file inputted second doesn't end with .txt
if not os.path.isfile(sequences_file) or sequences_file[-4:] != ".txt":
    print(f"Error: Expected .txt file, received {sequences_file[-4:]} file")
    sys.exit(3)

# Opens & reads the STR from the sequences file
with open(sequences_file) as dna_file:
    dna_reader = csv.reader(dna_file)
    for row in dna_reader:
        dna_list = row

# Moving the DNA list into a string, so we can parse it more easily to find sequences
dna = dna_list[0]

# Gets the sequences from the database so can keep track on what type of STR we're looking for
with open(database_file) as header_list:
    dna_headers = csv.reader(header_list)
    for row in dna_headers:
        dna_list = row
        dna_list.pop(0)
        break

# Moves sequences into a dictionary so the counter values can be added next
dna_sequence = {}
for d in dna_list:
    dna_sequence[d] = 1
    
# Goes through the STR, and when it finds a sequence it will count & record it   
for key in dna_sequence:
    dna_sequence[key] = 0
    str_length = len(key)
    # Scans through the whole of the dna sample
    for position in range(len(dna)):
        sequence_counter = 0
        # Finds the first match, then counts the length of the sequence
        while key == dna[position:(position + str_length)]:
            sequence_counter += 1
            position += str_length
        if dna_sequence[key] < sequence_counter:
            dna_sequence[key] = sequence_counter
    
# Opens & reads database file, trying to find a dna match
with open(database_file, newline='') as database:
    data = csv.DictReader(database)
    for person in data:
        # Variable for keeping track if a match has been found
        match_found = 0 
        # Scans through database, checking if anybody is a match
        for dna in dna_sequence:
            if dna_sequence[dna] == int(person[dna]):
                match_found += 1
        if match_found == len(dna_sequence):
            print(person['name'])
            sys.exit(0)
    print("No match")
    sys.exit(0)