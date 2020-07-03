import csv
import cs50
from sys import argv, exit

if len(argv) != 2:
    print('Usage: python import.py characters.csv')
    exit(1)
# # Create an empty shows.3db
# open('students.db', 'w').close()

# Open that file for sqlite
db = cs50.SQL("sqlite:///students.db")

# Create table clalled shows3 with the columns specified
# db.execute(
#     "CREATE TABLE students (first TEXT,middle TEXT,first last, birth NUMERIC")

with open(argv[1], 'r') as file:
    reader = csv.DictReader(file)

    for item in reader:
        name = item['name'].split()
        house = item['house']
        birth = int(item['birth'])

        if len(name) == 3:
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?,?)",
                       name[0], name[1], name[2], house, birth)
        else:
            db.execute("INSERT INTO students (first, last, house, birth) VALUES(?, ?, ?,?)",
                       name[0], name[1], house, birth)
