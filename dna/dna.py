from csv import reader, DictReader
from sys import argv

if len(argv) < 3:
    print("usage error, dna.py sequence.txt database.csv")
    exit()

# opening and reading the dna file
with open(argv[2]) as dnafile:
    dna_reader = reader(dnafile)
    for row in dna_reader:
        dnalist = row

# storeing it in a string & making a dictionary
dna = dnalist[0]
sequences = {}

# extracting the sequences from the database into a list
with open(argv[1]) as peoplefile:
    ppl_reader = reader(peoplefile)
    for row in ppl_reader:
        dna_seq = row
        dna_seq.pop(0)
        break

# copying the list in a dictionary where the genes are the keys
for item in dna_seq:
    sequences[item] = 1

# iterating trough the dna sequence & finding repetitions
for key in sequences:
    length = len(key)
    temp = 0
    tmax = 0

    for i in range(len(dna)):
        # after having counted a sequence it skips at the end of it to avoid counting again
        while temp > 0:
            temp -= 1
            continue


        if dna[i: i + length] == key:
            while dna[i - length: i] == dna[i: i + length]:
                temp += 1
                i += length

            # it compares the value to the previous longest sequence and if it is longer it overrides it
            if temp > tmax:
                tmax = temp

    # storing the longest sequences
    sequences[key] += tmax

# open and iterate trough the database of people treating each one like a dictionary so it can compare to the sequences one
with open(argv[1], newline='') as peoplefile:
    ppl = DictReader(peoplefile)
    for person in ppl:
        match = 0
        # compares the sequences to every person and prints name before leaving the program if there is a match
        for dna in sequences:
            if sequences[dna] == int(person[dna]):
                match += 1
        if match == len(sequences):
            print(person['name'])
            exit()

    print("No match")