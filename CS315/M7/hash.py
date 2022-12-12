# Enter Test Strings here

string_list = ["Bilbo", "Frodo", "Sam", "Gimli", "Merry", "Pippin", "John"]

R = 13
M = 11
for strings in string_list:
    print(strings)
    hash = 0
    for character in strings:

        hash = (R * hash + ord(character)) % M
        print(hash)
