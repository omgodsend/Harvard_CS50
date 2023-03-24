from cs50 import get_int

# python credit.py
def main():
    card = get_int("Number: ")

    while card <= 0:
         card = get_int("Number: ")

    card = str(card)

    if len(card) not in [13, 15, 16]:
         print("INVALID")
         break

    card_type = ""

    if len(card) == 15 and card[0] == "3" and card[1] in ["4", "7"]:
         card_type = "AMEX"
    elif len(card) == 16 and card[0] == "5" and card[1] in ["1", "2", "3", "4", "5"]:
         card_type = "MASTERCARD"
    elif (len(card) == 13 or len(card) == 16) and card[0] == "4":
         card_type = "VISA"
    else:
        card_type = "INVALID"

    print(card_type)

def validate(number):
     return













main()