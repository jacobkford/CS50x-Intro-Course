#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long credit;

    // Asks the user to input a credit card number.
    do
    {
        credit = get_long("Credit Card number: ");
    }
    // Checks if the user entered the credit card number correctly.
    while (credit <= 0);

    long check = credit;
    long digits = credit;
    int sum = 0;
    int count = 0;
    long divisor = 10;

    while (check > 0)
    {
        // Checks every first digit.
        int last = check % 10;
        sum += last;
        check /= 10;

        // Checks every second digit.
        last = check % 10;
        int x = last * 2;
        sum += (x % 10) + (x / 10);
        check /= 10;
    }
    // Checking amount of digits.
    while (digits > 0)
    {
        digits /= 10;
        count++;
    }
    // Finding the first digit.
    long first = credit;
    while(first >= 10)
    {
        first = first / 10;
    }
    // Finding the second digit.
    long first_two = credit;
    while(first_two >= 100)
    {
        first_two = first_two / 10;
    }

    int first_digit = first;
    int first_two_digits = first_two;

    // Final sumcheck.
    if (sum % 10 == 0)
    {
        // checks if VISA.
        if (first_digit == 4 && (count == 13 || count == 16))
        {
            printf("VISA\n");
        }
        // checks if American Express.
        else if ((first_two_digits == 34 || first_two_digits == 37) && count == 15)
        {
            printf("AMEX\n");
        }
        // checks if MasterCard.
        else if ((50 < first_two_digits && 56 > first_two_digits) && count == 16)
        {
            printf("MASTERCARD\n");
        }
        else
        // otherwise the card is invalid.
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
