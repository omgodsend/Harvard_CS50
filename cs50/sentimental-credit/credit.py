from cs50 import get_int
import sys

# python credit.py
def main():
    card = get_int("Number: ")

    while card <= 0:
         card = get_int("Number: ")

    card = str(card)

    if len(card) not in [13, 15, 16]:
         print("INVALID")
         sys.exit(1)

    if validate(card) == False
          print("INVALID")
          sys.exit(2)

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

     odd_sum = 0
     luhn_sum = 0

     for i, digit in enumerate(number):
    #Convert digit to integer
          digit_int = int(digit)

          if i % 2 == 0:
               times_two = digit_int * 2
          else:
               digit_odd = digit_int

          luhn_sum += times_two
          odd_sum += digit_odd

     final = odd_sum + luhn_sum

     if final % 10 == 0:
          return True
     else:
          return False










main()