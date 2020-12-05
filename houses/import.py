# TODO
from cs50 import SQL
from csv import reader
from sys import argv

# setting up database connection
db = SQL("sqlite:///students.db")

# error handling to check proper arguments
if len(argv) < 2:
    print("usage error, import.py characters.csv")
    exit()

# opening the csv file
with open(argv[1], newline='') as char_file:
    char_list= reader(char_file)
    for char in char_list:
        if char[0] == 'name':
            continue

        # splitting full name to get first, middle and last
        name = char[0].split()

        # inserting the name and other data in the database, null if no middle name
        if len(name) < 3:
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       name[0], None, name[1], char[1], char[2])

        else:
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       name[0], name[1], name[2], char[1], char[2])