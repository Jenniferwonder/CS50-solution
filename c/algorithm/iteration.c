#include <stdio.h>
#include <cs50.h>

void draw(int n);
int main(void)
{
    int height = get_int("Height: ");

    draw(height);
}

void draw(int n)
{
    //loop through heighr
    for (int i = 0; i < n; i++)
    {
        //loop through width
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}