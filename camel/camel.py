phrase = input("camelCase: ")

print("snake_case: ")

for letter in phrase:
    if letter.isupper():
        print("_" + letter.lower(), end="")
    else:
        print(letter, end="")


