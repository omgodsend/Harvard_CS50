phrase = input("camelCase: ")

print("snake_case: ")

for letter in phrase:
    if (letter.isupper()):
        print(phrase.lower(), sep="_")


