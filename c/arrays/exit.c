#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing command-line argument\n");
        // return 1 means sth goes wrong
        return 1;
    }
    printf("hello, %s\n", argv[1]);
    // 0 means everything works
    return 0;
}
