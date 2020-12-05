#include <cs50.h>
#include <stdio.h>

void spaces_printer(int n);
void hashes_printer(int n);

int main(void)
{
    //initializing the integer type variables
    int height, num_spaces, num_hashes;
    do
    {
        //asking the user for the pyramid's height from 1-8
        height = get_int("Choose the height of your pyramid from 1-8:");
    }
    while (height < 1 || height > 8);
    num_spaces = height - 1;
    num_hashes = 1;

    //building pyramind
    for (int i = 0; i < height; i++)
    {
        spaces_printer(num_spaces);
        hashes_printer(num_hashes);
        printf("\n");
        num_spaces--;
        num_hashes++;
    }
}

//-----functions------//

//this function prints the spaces in every line
void spaces_printer(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

//this function prints the hashes in every line
void hashes_printer(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}