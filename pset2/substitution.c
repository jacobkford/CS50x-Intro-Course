#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    int argl = 0;
    int upper_key[26];
    int lower_key[26];
    int dupe = 0;

    // Checking if the user provides a vaild number of inputs.
    if (argc == 2)
    {
        // Calculating how long the 2nd input is.
        argl = strlen(argv[1]);
        if (argl == 26)
        {
            for (int i = 0; i < 26; i++)
            {
                // Checking if the all the characters in the 2nd input are digits, returns message if 1 or more are not digits.
                if (!isalpha(argv[1][i]))
                {
                    printf("Usage: ./substitution key\n");
                    return 1;
                }
                else
                {
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
            }
            // Stating the variable for the cipher key.
        }
        else
        {
            printf("Usage: ./substitution key (26 Characters)\n");
            return 1;
        }
    }
    // Returns message if an incorrect amount of inputs is executed.
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // Asking the user for their text input.
    string input = get_string("plaintext: ");
    int text_length = strlen(input);
    printf("ciphertext: ");

    for (int j = 0; j < text_length; j++)
    {
        // Checking if the character is a letter.
        if (isalpha(input[j]))
        {
            // Checking if the letter is Uppercase.
            if (isupper(input[j]))
            {
                // This loop is checking the letter, starting at 65 (which is 'A' in ASCII), to see which letter it is & replace it with the correct ciphered key.
                for (int k = 65, y = 0; k <= 90; k++, y++)
                {
                    if (input[j] == k)
                    {
                        // Prints the ciphered character in Uppercase.
                        printf("%c", (((input[j] - 'A' - k) + upper_key[y]) + 'A'));
                    }
                }
            }
            else
            {
                // This loop is checking the letter, starting at 97 (which is 'a' in ASCII), to see which letter it is & replace it with the correct ciphered key.
                for (int l = 97, z = 0; l <= 122; l++, z++)
                {
                    if (input[j] == l)
                    {
                        // Prints the ciphered character in Lowercase.
                        printf("%c", (((input[j] - 'a' - l) + lower_key[z]) + 'a'));
                    }
                }
            }
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
