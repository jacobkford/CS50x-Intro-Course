#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    char upper_key[26];
    char lower_key[26];
    // Checking if the user provides a vaild number of inputs, and if the 2nd input is 26 digits in length.
    if (argc != 2 || strlen(argv[1]) != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    for (int i = 0; i < 26; i++)
    {
        // Checking if the all the characters in the 2nd input are digits, returns message if 1 or more are not digits.
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
        // Checking for duplicate characters.
        for (int d = 0; d < i; d++)
        {
            if (argv[1][i] == argv[1][d])
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
        // Creating an uppercase & lowercase version of the key.
        upper_key[i] = toupper(argv[1][i]);
        lower_key[i] = tolower(argv[1][i]);
    }
    // Asking the user for their text input.
    string input = get_string("plaintext: ");
    int text_length = strlen(input);
    printf("ciphertext: ");

    // This loop is checking the letter to see which letter it is & replace it with the correct ciphered key. If it isn't a letter, it will leave it alone.
    for (int j = 0; j < text_length; j++)
    {
        if (isupper(input[j]))
        {
            for (int k = 65, y = 0; k <= 90; k++, y++)
            {
                if (input[j] == k)
                {
                    // Prints the ciphered character in Uppercase.
                    printf("%c", (((input[j] - 'A' - k) + upper_key[y]) + 'A'));
                }
            }
        }
        else if (islower(input[j]))
        {
            for (int l = 97, z = 0; l <= 122; l++, z++)
            {
                if (input[j] == l)
                {
                    // Prints the ciphered character in Lowercase.
                    printf("%c", (((input[j] - 'a' - l) + lower_key[z]) + 'a'));
                }
            }
        }
        else
        {
            // Prints every character that isn't a letter, untouched.
            printf("%c", input[j]);
        }
    }
    // Prints a new line once all characters have been sorted & ciphered, then ends the program.
    printf("\n");
    return 0;
}
