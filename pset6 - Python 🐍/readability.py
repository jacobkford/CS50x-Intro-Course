from cs50 import get_string
from sys import exit

# Asks user for input a string of text, it will repeat the question if nothing is entered
text = get_string("Text: ")

# Counts the amount of letters in the text
def LetterCount(text):
    letter_count = 0
    for i in range(len(text)):
        if text[i].isalpha():
            letter_count += 1
    return letter_count

letters = LetterCount(text)

# Counts the amount of words in the text
def WordCount(text):
    word_count = 0
    for j in range(len(text)):
        if text[j].isspace():
            word_count += 1
    # Adds 1 extra to the count, since the last word will not be counted
    word_count += 1
    return word_count

words = WordCount(text)

# Counts the amount of sentences in the text
def SentenceCount(text):
    sentence_count = 0
    for k in range(len(text)):
        if text[k] == '.' or text[k] == '!' or text[k] == '?':
            sentence_count += 1
    return sentence_count

sentences = SentenceCount(text)

# Calculates the readability level of the text using the Coleman-Liau Index
def CLI(letter_count, word_count, sentence_count):
    # Calculates averages
    average_letters = letter_count / word_count * 100
    average_sentences = sentence_count / word_count * 100
    # Coleman-Liau Index equation
    index = round(0.0588 * average_letters - 0.296 * average_sentences - 15.8)
    return index

grade = CLI(letters, words, sentences)

# Checking if index is less than Grade 1 material
if grade < 1:
    print("Before Grade 1")
# Checking if index is either Grade 16 material or above
elif grade >= 16:
    print("Grade 16+")
# Prints the grade score for the material
else:
    print(f"Grade {grade}")
exit(0)
