from cs50 import get_string


def main():
    # Ask users for text
    text = get_string("Text: ")

    # Count letters
    letters = count_letters(text)

    # Count words
    words = count_words(text)

    # Count sentences
    sentences = count_sentences(text)

    # Count L: the average number of letters per 100 words
    L = letters / words * 100

    # Count S: the average number of sentences per 100 words
    S = sentences / words * 100

    # Coleman-Liau index
    index = 0.0588 * L - 0.296 * S - 15.8
    if index <= 16 and index >= 1:
        print("Grade ", +(int(round(index))))
    elif index < 1:
        print("Before Grade 1")
    else:
        print("Grade 16+")


def count_letters(text):
    letters = 0.0
    # for (int i = 0; text[i] != '\0'; i++):
    for c in text:
        # check whether a character is alphabetical
        if (c.isalpha()):
            letters += 1
    return letters


def count_words(text):
    words = 1.0
    for c in text:
        # check whether a character is space
        if (c.isspace()):
            words += 1
    return words


def count_sentences(text):
    sentences = 0.0
    for c in text:
        # check whether a character is a sentence
        if c == '.' or c == '!' or c == '?':
            sentences += 1
    return sentences


main()

