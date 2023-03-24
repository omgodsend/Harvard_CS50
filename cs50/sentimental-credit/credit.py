from cs50 import get_int

def main():
    try:
        card = get_int("Number: ")
        if card > 0:
            return card
    except ValueError:
            print("Not and integer")

    if len(card) != 13 or len(card) != 15 or len(card) != 16:
         print("INVALID")

    card_str = str(card)

    if card_str[0] == "3" and (card_str[1] == "4" or card_str[1] == "7"):
         card_type = "AMEX"


def algorithm(number):













main()