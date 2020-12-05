#include <stdio.h>
#include <math.h> //needed for the module function
#include <cs50.h>

int main(void)
{
    float owed_change;
    int change;

    do
    {
        //propmting the user to input the change owed
        owed_change = get_float("Enter the amount of change owed: ");
    }
    while (owed_change < 0);

    //converting dollars to cents
    change = round(owed_change * 100);

    //initializing the number of coins
    int num_coins = 0;

    //using the modulo function to know if the current change owed is divisible by 25
    num_coins += change / 25;
    change %= 25;

    //using the modulo function to know if the current change owed is divisible by 10
    num_coins += change / 10;
    change %= 10;

    //using the modulo function to know if the current change owed is divisible by 5
    num_coins += change / 5;
    change %= 5;

    //using the modulo function to know if the current change owed is divisible by 1
    num_coins += change / 1;
    change %= 1;

    printf("%d\n", num_coins);

}