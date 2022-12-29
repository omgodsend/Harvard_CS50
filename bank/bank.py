phrase = input("Greeting: ").lower()

if phrase.startswith("h") and phrase != "hello":
    print ("$20")
elif phrase == "hello":
    print("$0")
else:
    print("$100")