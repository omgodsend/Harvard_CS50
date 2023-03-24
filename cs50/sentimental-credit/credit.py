from cs50 import get_int

def main():

    card = get_int("Number: ")
    
    while card <= 0:
         card = get_int("Number: ")

    if len(card) not in [13, 15, 16]:
         print("INVALID")

    card_str = str(card)

    if card_str[0] == "3" and (card_str[1] == "4" or card_str[1] == "7"):
         card_type = "AMEX"


def algorithm(number):
     return













main()