import csv

with open('title.basics.tsv', 'r') as file:
    reader = csv.DictReader(file, delimiter='\t')
    # print(next(reader))
    with open('show0.csv', 'w') as file2:
        writer = csv.writer(file2)
        writer.writerow(['tconst', 'primaryTitle', 'startYear', 'genres'])

        for row in reader:
            if row['startYear'] == '\\N':
                continue
            if row['titleType'] == 'tvSeries' and row['isAdult'] == '0':
                continue
            if int(row['startYear']) <= 1970:
                continue
            writer.writerow([row['tconst'], row['primaryTitle'],
                             row['startYear'], row['genres']])
