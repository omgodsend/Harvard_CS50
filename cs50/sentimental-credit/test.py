from cs50 import get_int
import sys

def main():
    
    while int(card) <= 0:
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
     reversed_number = int(str(number)[::-1])

     counter = 1
     digit_odd = 0
     luhn_sum = 0

     for i in str(reversed_number):
          digit_int = int(i)

          if counter % 2 == 0:
               luhn_sum += digit_int * 2
          else:
               digit_odd += digit_int
     counter += 1

     final = digit_odd + luhn_sum

     if final % 10 == 0:
          return "VALID"
     else:
          return "INVALID"