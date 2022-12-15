def main():
    text = input("enter phrase: ")
    result = convert(text)
    print(result)

def convert(text):
    smile = text.replace [":)","\U0001F642"]
    sad = text.replace [":(","\U0001F641"]
    return text

main()