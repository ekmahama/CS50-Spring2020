import cs50
import csv

# Create an empty shows.3db
open('shows3.db', 'w').close()

# Open that file for sqlite
db = cs50.SQL("sqlite:///shows3.db")

# Create table clalled shows3 with the columns specified
db.execute("CREATE TABLE shows (id INT,title TEXT, year NUMERIC, PRIMARY KEY(id))")
db.execute(
    "CREATE TABLE genres (show_id INT,genre TEXT, FOREIGN KEY(show_id) REFERENCES shows(id))")

with open('title.basics.tsv', 'r') as file:
    reader = csv.DictReader(file, delimiter='\t')

    for row in reader:
        if row['startYear'] == '\\N':
            continue
        if row['titleType'] == 'tvSeries' and row['isAdult'] == '0':
            if int(row['startYear']) < 1970:
                continue

            id = int(row['tconst'][2:])
            year = row['startYear']
            genres = row['genres']
            title = row['primaryTitle']

            db.execute("INSERT INTO shows (id, title, year) VALUES(?, ?, ?)",
                       id, title, year)

            if row['genres'] != '\\N':
                for genre in row['genres'].split(','):
                    db.execute(
                        "INSERT INTO genres(show_id ,genre) VALUES(?,?)", id, genre)
                    # print(genre)
