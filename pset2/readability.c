#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

float LetterCount(string x);
float WordCount(string y);
float SentenceCount(string z);
float AverageLetters(float a, float b);
float AverageSentences(float c, float d);
float CLIndex(float e, float f);

int main(void)
{
    string input;
    int input_length = 0;
    // Asks the user to input a string of text.
    do
    {
        input = get_string("Text: ");
        input_length = strlen(input);
        // Checks if the user entered something, if not it will return the question.
    }
    while (input_length <= 0);
    
    // Checking the amount of Letters, Words and Sentences that were inputted.
    float l = LetterCount(input), w = WordCount(input), s = SentenceCount(input);
    // Calculating the average of letters per 100 words, and sentences per 100 words.
    float avgl = AverageLetters(l, w), avgs = AverageSentences(s, w);
    // Calculating the Coleman-Liau readability test result for the users inputted sentence(s)/paragraph(s).
    float index = CLIndex(avgl, avgs);
    // Checking if the answer is less than Grade 1 material.
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    // Checking if the answer is either Grade 16 or above material.
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    // Prints the grade score for the material provided.
    else
    {
        printf("Grade %i\n", (int) index);
    }
}

// This function will calculate the total amount of Letters inputted.
float LetterCount(string x)
{
    float letter_count = 0;
    // Loops through each individual value that's inputted.
    for (int i = 0, n = strlen(x); i < n; i++)
    {
        // Checking if the value is a letter (uppercase & lowercase).
        if (islower(x[i]) || isupper(x[i]))
        {
            letter_count++;
        }
    }
    return letter_count;
}

// This function will calculate the total amount of Words inputted.
float WordCount(string y)
{
    float word_count = 0;
    // Loops through each individual value that's inputted.
    for (int j = 0, o = strlen(y); j < o; j++)
    {
        // Checking if the value is a space/whitespace
        if (isspace(y[j]))
        {
            word_count++;
        }
    }
    // Adds 1 to the count, since the last word will not be counted due to a space/whitespace not being inputted.
    word_count += 1;
    return word_count;
}

// This function will calculate the total amount of Sentences inputted.
float SentenceCount(string z)
{
    float sentence_count = 0;
    char dot = '.', bang = '!', question = '?';
    // Loops through each individual value that's inputted.
    for (int k = 0, p = strlen(z); k < p; k++)
    {
        // Checking if the value is a ".", "!" or "?".
        if (z[k] == dot || z[k] == bang || z[k] == question)
        {
            sentence_count++;
        }
    }
    return sentence_count;
}

// This function will calculate the average amount of Letters used per 100 words.
float AverageLetters(float a, float b)
{
    // a = Total amount of Letters.
    // b = Total amount of Words.
    float average_letters = a / b * 100;
    return average_letters;
}

// This function will calculate the average amount of Sentences used per 100 words.
float AverageSentences(float c, float d)
{
    // c = Total amount of Sentences.
    // d = Total amount of Words.
    float average_sentences = c / d * 100;
    return average_sentences;
}

// This function (using the Coleman-Liau Index) will calculate readablilty level.
float CLIndex(float e, float f)
{
    // e = Average Letters
    // f = Average Sentences
    float CLI = round(0.0588 * e - 0.296 * f - 15.8);
    return CLI;
}
