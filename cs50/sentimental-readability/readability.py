from cs50 import get_string

def main():

    all = get_string("Text: ")

    index = 0.0588 * L - 0.296 * S - 15.8

    letters = count_letters(all);
    words = count_words(all);
    int sent = count_sentences(all);
