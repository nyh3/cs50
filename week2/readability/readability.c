#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: "); // Stores the input text

    int letters = count_letters(text); // Stores the number of letters
    float words = (float)count_words(text) / 100; // Counts of 100 words
    int sentences = count_sentences(text); // Stores the number of sentences
    float L = (float)letters / words; // Average number of letters per 100 words
    float S = (float)sentences / words; // Average number of sentences per 100 words
    int index = round(0.0588 * L - 0.296 * S - 15.8); // Calculates the grade level
    printf("%f\n", words);
    printf("%f\n", L);
    printf("%f\n", S);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// Counts the number of letters
int count_letters(string text)
{
    int length = strlen(text);
    int letters = 0;
    for (int i = 0; i < length; i += 1)
    {
        if (isalpha(text[i]))
        {
            letters += 1;
        }
    }
    return letters;
}

// Counst the number of words
int count_words(string text)
{
    int length = strlen(text);
    int words = 1;
    for (int i = 0; i < length; i += 1)
    {
        if (isblank(text[i]))
        {
            words += 1;
        }
    }
    return words;
}

// Count the number of sentences
int count_sentences(string text)
{
    int length = strlen(text);
    int sentences = 0;
    for (int i = 0; i < length; i += 1)
    {
        if (text[i] == 46 || text[i] == 63 || text[i] == 33)
        {
            sentences += 1;
        }
    }
    return sentences;
}