#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string names[] = {"Bill", "Jen", "Vicky", "Gin", "Percy", "Ron", "Bob"};

    for (int i = 0; i < 7; i++)
    {
        // To compare strings "==" can not be used; instead use "int strcmp(string s1, string s2)"
        // if (names[i] == "Ron")
        if (strcmp(names[i], "Ron") == 0) //==0: true
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}