#include <stdio.h>
#include <cs50.h>
#include <string.h>

// linear search; binary search
// selection sort; bubble sort; recurssion: programming/mathematical technique = a function calls itself; merge sort

// Version 2:
// To couple names and numbers, by using data structure (defining data type)
// To encapsulate or contain related pieces of info, eg. using "person" to encapsulate "name" and "number"
typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[2];
    //. : go inside that structure and access the variable called name and give it this value "*"
    people[0].name = "Carter";
    people[0].number = "+1-617-495-1000";
    people[1].name = "David";
    people[1].number = "+1-949-468-2750";

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name, "David") == 0)
        {
            printf("Found %s\n", people[i].number); // How to couple names and numbers? Data structure
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}

/* Version 1
int main(void)
{
    string names[] = {"Carter", "David"};
    string numbers[] = {"+1-617-495-1000", "+1-949-468-2750"};

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(names[i], "David") == 0)
        {
            printf("Found %s\n", numbers[i]); // How to couple names and numbers? Data structure
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}*/