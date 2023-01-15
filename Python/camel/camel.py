phrase = input("camelCase: ")

print("snake_case: ", end="")

for letter in phrase:
    if letter.isupper():
      print("_" + letter.lower(), end="")
    else:
     print(letter, end="")
print()