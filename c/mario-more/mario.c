#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int row, height, space, lefthash = 0, righthash = 0;
    do
    {
        height = get_int("height: ");

    }
    while (height < 1 || height > 8);
    // For each row
    for (row = 1; row <= height; row++, lefthash = 0)
    {
        // Print spaces for each row
        for (space = 1; space <= height - row; space++)
        {
            printf(" ");
        }
        // Print left hashes for each row
        while (lefthash != row)
        {
            printf("#");
            lefthash++;
            // Print gap for each row
            if (lefthash == row)
            {
                printf("  ");
            }
        }
        // Print right hashes for each row
        for (righthash = 0; righthash != row; righthash++)
        {
            printf("#");
        }
        // Move to next row
        printf("\n");
    }
}
