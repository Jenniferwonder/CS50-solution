#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int only_digits(string key);
void get_ciphertext(string text);
int k = 0;

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //else printf("Success\n");

    // Define the key
    string key = argv[1]; //Note: argv[1] is a string!

    // Make sure the key is a digit number
    if(only_digits(key) != 0)
    {
        printf("Usage: ./caesar key\n");
    }

    // Ask for plaintext
    string plaintext = get_string("plaintext:  ");

    // Convert key to integer
    k = atoi(key);

    // Get ciphertext
    get_ciphertext(plaintext);
    //printf("ciphertext: %c %c %c \n", c1, c2, c3);}
}

void get_ciphertext(string text)
{
    char cipher_text=0;
    printf("ciphertext: ");

    for (int i = 0; i < strlen(text); i++)
    {
        if (isupper(text[i]))
        {
            // How to rotate? c[i] = (p[i] + k) % 26
            // modulo %26: take the remainder when divided by 26
            cipher_text = ((text[i] - 65 + k)% 26) + 65 ;
        }
        else if (islower(text[i]))
        {
            cipher_text = ((text[i] - 97 + k) % 26) + 97 ;
        }
        else
        {
            cipher_text = text[i];
        }
        printf("%c", cipher_text);
    }
    printf("\n");
}

int only_digits(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (isdigit(key[i] == 0))//This function returns 0 if c is not a decimal digit.
        {
            return 1;
        }
    }
    return 0;
}




// int main(int argc, string argv[])
// {
//     // Make sure program was run with just one command-line argument
//     if (argc != 2)
//     {
//         printf("Usage: ./caesar key\n");
//         return 1;
//     }
//     //else printf("Success\n");

//     // Define the key
//     string key = argv[1]; //Note: argv[1] is a string!

//     // Check that the key is a digit
//     for (int i = 0; i < strlen(key); i++)
//     {
//         if (!isdigit(key[i]))
//         {
//             printf("Usage: ./caesar key\n");
//             return 1;
//         }
//     }
//     //printf("Success\n%s\n", key);

//     // Ask for plaintext
//     string plaintext = get_string("plaintext:  ");

//     // Convert key to integer
//     int k = atoi(key);

//     // Get ciphertext
//     printf("ciphertext: ");
//     for (int i = 0; i < strlen(plaintext); i++)
//     {
//         if (isupper(plaintext[i]))
//         {
//             // How to rotate? c[i] = (p[i] + k) % 26
//             // modulo %26: take the remainder when divided by 26
//             char c = (plaintext[i] - 65 + k) % 26;
//             printf("%c", c + 65);
//         }
//         else if (islower(plaintext[i]))
//         {
//             char c = (plaintext[i] - 97 + k) % 26;
//             printf("%c", c + 97);
//         }
//         else
//         {
//             printf("%c", plaintext[i]);
//         }
//     }
//     printf("\n");
//     //Reference: Decimal ASCII CHART lowercase letters are between 97 and 122
// }