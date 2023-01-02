phrase = input("camelCase: ")

print("snake_case: ")


for letter in phrase:
    print(letter, sep="_", end="")

if letter in phrase.isupper:
    print(letter)



