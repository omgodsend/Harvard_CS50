from cs50 import get_int

def main():
    try:
        card = get_int("Number: ")
        return card
    except ValueError:
            print("Not and integer")

    if card < 0:
        print("Enter a valid card")

    if len(card) not in [13, 15, 16]:
         print("INVALID")

    card_str = str(card)

    if card_str[0] == "3" and (card_str[1] == "4" or card_str[1] == "7"):
         card_type = "AMEX"


def algorithm(number):
     return













main()