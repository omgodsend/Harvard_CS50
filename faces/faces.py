def main():
    text = input("enter phrase: ")
    result = convert(text)
    print(result)

def convert(text):
    smile = text.replace (":)","🙂")
    sad = smile.replace (":(","🙁")
    return text

main()