import cs50
import csv

# Create an empty shows.3db
open('shows3.db', 'w').close()

# Open that file for sqlite
db = cs50.SQL("sqlite:///shows3.db")

# Create table clalled shows3 with the columns specified
db.execute(
    "CREATE TABLE shows3 (tconst TEXT,primaryTitle TEXT, startYear NUMERIC, genres TEXT)")

with open('title.basics.tsv', 'r') as file:
    reader = csv.DictReader(file, delimiter='\t')

    for row in reader:
        if row['startYear'] == '\\N':
            continue
        if row['titleType'] == 'tvSeries' and row['isAdult'] == '0':
            if int(row['startYear']) >= 1970:
                tconst = row['tconst']
                startYear = row['startYear']
                genres = row['genres']
                primaryTitle = row['primaryTitle']

                db.execute("INSERT INTO shows3(tconst, primaryTitle, startYear, genres) VALUES(?, ?, ?, ?)",
                           tconst, primaryTitle, startYear, genres)
