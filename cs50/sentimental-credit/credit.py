from cs50 import get_int
import sys
import re

# python credit.py
def main():

    card = get_int("Number: ")

    while True:
         card = get_int("Number: ")
         if card > 0:
              break

    if validate(card) == "INVALID":
          print("INVALID")
          sys.exit(2)

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

     def digits_of(n):
          return [int(i) for i in str(n)]

     digits = digits_of(number)
     odd_digits = digits[-1::-2]
     even_digits = digits[-1:-2]

     luhnsum = 0

     luhnsum += sum(odd_digits)
     for i in even_digits:
          luhnsum += sum(digits_of(i*2))

     return checksum % 10


main()