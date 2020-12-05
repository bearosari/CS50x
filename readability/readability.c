#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    //prompting user for the text to be graded

    string text = get_string("Enter text: ");
    float index;
    int letter_count = 0;
    int word_count = 1; //taken into account that the last word will not have a space after it
    int sentence_count = 0;

    //iterating through every character in the input string

    for (int i = 0; i < strlen(text); i++)
    {
        //counting letters based on alphabet
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letter_count++;
        }
        //counting words 1 word every after a space
        else if (text[i] == ' ')
        {
            word_count++;
        }
        //counting sentences per punctuation mark
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_count++;
        }
    }

    // Coleman-Liau index
    index = 0.0588 * (100 * (float) letter_count / (float) word_count) - 0.296 * (100 * (float) sentence_count /
            (float) word_count) - 15.8;

    //printing output based on index standards
    if (index < 16 && index >= 0)
    {
        printf("Grade %i\n", (int) round(index));
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
}