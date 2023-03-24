from cs50 import get_int

# python credit.py
def main():
    card = get_int("Number: ")

    while card <= 0:
         card = get_int("Number: ")

    card = str(card)

    if len(card) not in [13, 15, 16]:
         print("INVALID")

    if (len(card) == 15) and (card[0] == "3" and (card[1] == "4" or card[1] == "7")):
         card_type = "AMEX"
    else if (len(card) == 16) and (card[0] == "3" and 

def algorithm(number):
     return













main()