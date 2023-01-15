def main():
    text = convert(input("Message: "))
    print(text)


def convert(text):
    text = text.replace(":)","🙂")
    text = text.replace(":(","🙁")
    return text

main()