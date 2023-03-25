from cs50 import get_int
import sys

# python credit.py
def main():
    card = input("Number: ")

    while not card.isdigit():
        card = input("Number: ")

    if validate(card) == "INVALID":
          print("INVALID")
          sys.exit(2)

    card = str(card)

    if len(card) not in [13, 15, 16]:
         print("INVALID")
         sys.exit(1)

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

     digit_odd = 0
     odd_sum = 0
     luhn_sum = 0

     for i in number:

          if i % 2 == 0:
               luhn_sum += i * 2
          else:
               digit_odd += i

          odd_sum += digit_odd

     final = odd_sum + luhn_sum

     if final % 10 == 0:
          return "VALID"
     else:
          return "INVALID"


main()