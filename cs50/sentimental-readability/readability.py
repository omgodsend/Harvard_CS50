from cs50 import get_string
import re

def main():

    all = get_string("Text: ")

    ##index = 0.0588 * L - 0.296 * S - 15.8



    letters = count_letters(all)
    words = count_words(all)
    sent = count_sentences(all)

def count_letters(text):

    letters = 0

    for char in text:
        if char.isalpha():
            letters += 1
    print(letters)
    return letters


def count_words(text):

   word_re = re.compile(r'\b\w+\b')
   word_count = len(word_re.findall(text))
   print(word_count)
   return word_count

def count_sentences(text):

    ending = ['.', '!', '?']
    num_sent = 0

    for i in range(len(text)):

        if text[i] in ending:
            num_sent += 1

    return num_sent



main()