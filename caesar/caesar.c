#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int is_all_digits(string str);


int main(int argc, string argv[])
{

//to check if there are 2 arguments and is a number else prompts the user again
    if (argc == 2 && is_all_digits(argv[1]))
    {

        int k = atoi(argv[1]); // converting the user-input caesar value into integer
        string txt = get_string("plaintext: "); //prompting the user fot the text to be encrypted
        printf("ciphertext: "); //printing the encrypted cipher message

        //printf("%i", bool(isdigit(*argv[1])));



        //iterating thru every character in input text
        for (int i = 0, n = strlen(txt); i < n; i++)
        {
            if (txt[i] >= 'a' && txt[i] <= 'z') //lowercase conditions
            {
                printf("%c", (((txt[i] - 'a') + k) % 26) + 'a');
            }
            else if (txt[i] >= 'A' && txt[i] <= 'Z') //uppercase conditions
            {
                printf("%c", (((txt[i] - 'A') + k) % 26) + 'A');
            }
            else
            {
                printf("%c", txt[i]);
            }
        }

        printf("\n");
        return 0;
    }

    //returning to instructions is key is invalid
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}


int is_all_digits(string text)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            return 0;
        }

    }
    return 1;
}
