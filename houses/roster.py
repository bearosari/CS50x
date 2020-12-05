# TODO
from cs50 import SQL
from sys import argv

#error handling to check proper arguments
if len(argv) < 2:
    print("usage error, roster.py houseName")
    exit()

# setting up database connection
db = SQL("sqlite:///students.db")
#executing query that lists character in a house in alphabetical order
people = db.execute("SELECT * FROM students WHERE house = (?) ORDER BY last", argv[1])

# printing student information
for person in people:
    if person['middle'] != None:
        print(f"{person['first']} {person['middle']} {person['last']}, born {person['birth']}")
    else:
        print(f"{person['first']} {person['last']}, born {person['birth']}")
