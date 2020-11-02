#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;
    // Asks the user to input the amount of change owed to them.
    do
    {
        dollars = get_float("Change owed: ");
    }
    // Checks if the user entered a positive number, will return question if condition hasn't been met.
    while (dollars <= 0);

    // Converting currency from Dollars to Cents.
    int cents = round(dollars * 100);
    int coins = 0;

    // Checks if it can return a Quarter.
    while (cents >= 25)
    {
        cents -= 25;
        coins++;
    }
    // Checks if it can return a Dime.
    while (cents >= 10)
    {
        cents -= 10;
        coins++;
    }
    // Checks if it can return a Nickel.
    while (cents >= 5)
    {
        cents -= 5;
        coins++;
    }
    //Checks if it can return a Penny.
    while (cents >= 1)
    {
        cents -= 1;
        coins++;
    }
    // Returns a value equal to the amount of change returned.
    printf("%i\n", coins);
}
