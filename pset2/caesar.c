#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

char caesar(char p, int key);

int main(int argc, string argv[])
{
    int key = 0;
    int argl = 0;
    string input;

    // Checking if the user provides a vaild number of inputs.
    if (argc == 2)
    {
        // Calculating how long the 2nd input is.
        argl = strlen(argv[1]);
        for (int i = 0; i < argl; i++)
        {
            // Checking if the all the characters in the 2nd input are digits, returns message if 1 or more are not digits.
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        // Stating the variable for the cipher key.
        key = atoi(argv[1]);
    }
    // Returns message if an incorrect amount of inputs is executed.
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Asking the user for their text input.
    input = get_string("plaintext: ");
    int text_length = strlen(input);
    printf("ciphertext: ");

    // We will be looping through each character in the text provided by the user.
    for (int j = 0, k = 0; j < text_length; j++)
    {
        // Checking if the character is a letter.
        if (isalpha(input[j]))
        {
            // Prints the ciphered character.
            printf("%c", caesar(input[j], key));
        }
        // If it isn't a letter, it doesn't get ciphered.
        else
        {
            // Prints every character that isn't a letter, untouched.
            printf("%c", input[j]);
        }
    }
    // Prints a new line once all characters have been sorted & ciphered.
    printf("\n");
    return 0;
}

// This is the 'caesar cipher' function, which supports case sensativity input.

char caesar(char p, int key)
{
    // Encryption for uppercase letters.
    if (isupper(p))
    {
        return ((p - 'A' + key) % 26) + 'A';
    }
    // Encryption for lowercase letters.
    else
    {
        return ((p - 'a' + key) % 26) + 'a';
    }
}
