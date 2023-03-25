from cs50 import get_int
import sys
import re

# python credit.py
def main():

    while True:
         card = get_int("Number: ")
         if card > 0:
              break

    if validate(card) == 0:
         card_type = checkcard(card)
         print(card_type)
    else:
          print("INVALID")
          sys.exit(2)

def checkcard(card_num)
    type = ""
    card_num_str = str(card_num)

    if len(card_num_str) == 15 and card_num_str.startswith("34") or card_num_str.startswith("37"):
         type = "AMEX"
    elif len(card_num_str) == 16 and card_num_str.startswith("5") and card[1] in ["1", "2", "3", "4", "5"]:
         type = "MASTERCARD"
    elif (len(card_num_str) == 13 or len(card_num_str) == 16) and card_num_str.startswith("5"):
         type = "VISA"
    else:
        type = "INVALID"

    return type

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

     return luhnsum % 10


main()