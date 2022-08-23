#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int row, height, space, hash = 0;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Print for each row
    for (row = 1; row <= height; row++, hash = 0)
    {
        //Print space for each row
        for (space = 0; space < height - row; space++)
        {
            printf(" ");
        }
        //Print hash for each row
        while (hash != row)
        {
            printf("#");
            hash++;
        }
        //Move to the next row
        printf("\n");
    }
}