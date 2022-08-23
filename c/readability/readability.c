#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //To test
    //printf("%d\n", ' ');

    //Ask users for text
    string text = get_string("Text: ");
    printf("%s\n", text);

    //Count letters
    float letters = count_letters(text);
    //printf("%f letters\n", letters);

    //Count words
    float words = count_words(text);
    //printf("%f words\n", words);

    //Count sentences
    float sentences = count_sentences(text);
    //printf("%f sentences\n", sentences);

    //Count L: the average number of letters per 100 words
    float L = letters / words * 100;
    //printf("L= %f\n", L);

    //Count S: the average number of sentences per 100 words
    float S = sentences / words * 100;
    //printf("S= %f\n", S);

    //Coleman-Liau index
    float index = 0.0588 * L - 0.296 * S - 15.8;
    if (index <= 16 && index >= 1)
    {
        printf("Grade %i\n", (int) round(index));
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text)
{
    float letters = 0.0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))//check whether a character is alphabetical
            //2nd version of checking whether a character is alphabetical
            //if (((text[i]>='A')&&(text[i]<='Z')) || ((text[i]>='a')&&(text[i]<='z')))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    float words = 1.0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isspace(text[i]))//check whether a character is space
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    float sentences = 0.0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        //check whether a character is a sentence
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}

//printf("%d %d %d %d \n", 'a','z','A','Z');//To test

//2nd version of count_letters in a string
/*int count_letters_t(string text)
{
    int i;
    int letters=0;

    int n = strlen(text);
    printf("n= %d\n", n);
    for (i = 0; i < n; i++)
    {
        if(islower(text[i]) != 0 || isupper(text[i]) != 0)
        {
            letters++;
            printf("q\n");
        }
    }
     printf("\n");
     return letters;
}*/