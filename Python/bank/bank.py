phrase = input("Greeting: ").lower().strip()

if phrase.startswith("h") and not phrase.startswith("hello") and phrase != "hello":
    print ("$20")
elif phrase.startswith("hello"):
    print("$0")
else:
    print("$100")