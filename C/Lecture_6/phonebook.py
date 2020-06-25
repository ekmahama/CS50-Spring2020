import csv


name = input("enter name: ")
number = input("enter number: ")


with open("phonebook.csv", "a") as file:
    writer = csv.writer(file)
    writer.writerow((name, number))
