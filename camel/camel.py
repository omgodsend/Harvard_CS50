phrase = input("camelCase: ")

print("snake_case: ")


for letter in phrase:
    print(letter, sep="_", end="")

while letter in phrase.isupper():
    print(letter, sep="_")



