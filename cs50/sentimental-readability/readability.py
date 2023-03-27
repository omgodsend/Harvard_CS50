from cs50 import get_string

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

    word_count = 0

    for "" in text:
        word_count += 1

