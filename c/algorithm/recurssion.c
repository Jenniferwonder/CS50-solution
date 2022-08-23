#include <stdio.h>
#include <cs50.h>

//merge sort: using recurssion- keep looking at the beginning of two lists using more memory but "n*logn" running time vs "n*n"
void draw(int n);
int main(void)
{
    int height = get_int("Height: ");

    draw(height);
}

void draw(int n)
{
    if (n <= 0)
    {
        return;
    }

    draw(n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}

//Version 1
/*    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}*/