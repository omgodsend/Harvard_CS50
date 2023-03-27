from cs50 import get_string
import re
import nltk

def main():

    all = get_string("Text: ")

    index = 0.0588 * L - 0.296 * S - 15.8



    letters = count_letters(all)
    words = count_words(all)
    sent = count_sentences(all)

def count_letters(text):

    letters = len(text)
    return letters

def count_words(text):

   word_re = re.compile(r'\b\w+\b')
   word_count = len(word_re.findall(text))
   return word_count

def count_sentences(text):

    sentences= nltk.sent_tokenize(text)
    length= len(sentences)




main()