#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = get_int("How many scores? ");

    float scores[n], sum = 0.0, avg;

    for (int i = 0; i < n; i++)
    {
        scores[i] = get_int("Score: ");
        sum += scores[i];
    }

    avg = sum / n;
    printf("Average: %f\n", avg);
}
