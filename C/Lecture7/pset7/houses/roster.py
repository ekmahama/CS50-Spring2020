import cs50
from sys import argv, exit

# CHeck for correct input
if len(argv) != 2:
    print('Usage: python roster.py Gryffindor')
    exit(1)

# Open that file for sqlite
db = cs50.SQL("sqlite:///students.db")
house = argv[1]

# Execute Query
res = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last", house)

for student in res:
    first = student['first']
    last = student['last']
    birth = student['birth']
    if student['middle'] != None:
        middle = student['middle']
        print(f'{first}, {middle}, {last} born, {birth}')
    else:
        print(f'{first}, {last} born, {birth}')
