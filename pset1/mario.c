#include <stdio.h>
#include <cs50.h>

void build_row(int n);

int main(void)
{
    int h;
    // Asks the user to input the height value
    do
    {
        h = get_int("Height: ");
    }
    // Checks if the user entered a number between 1 & 8
    // If not, it will repeat the same question until condition becomes true.
    while (h > 8 || h < 1);

    // Loop for building the shape
    for (int i = 0; i < h; i++)
    {
        // Loop for calculating and print the spaces at the beginning of each line.
        for (int j = 0; j < h - i - 1; j++)
        {
            printf(" ");
        }
        // Creates the shape
        build_row(i);
    }
}
void build_row(int n)
{
    // Builds the first half of the shape for that line.
    for (int k = 0; k <= n; k++)
    {
        printf("#");
    }
    // Creates the centre of area of the shape for that line.
    printf("  ");
    // Creates the second half of the shape for that line.
    for (int l = 0; l <= n; l++)
    {
        printf("#");
    }
    // Starts the next line
    printf("\n");
}
