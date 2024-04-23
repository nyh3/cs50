#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("Change owed: "); //Stores the total change
    }
    while (cents < 0);
    return cents;
}

int calculate_quarters(int cents)
{
    int q; //Store the number of quarters
    for (q = 0; cents / 25 > 0; cents -= 25)
    {
        q += 1;
    }
    return q;
}

int calculate_dimes(int cents)
{
    int d; //Stores the number of dimes
    for (d = 0; cents / 10 > 0; cents -= 10)
    {
        d += 1;
    }
    return d;
}

int calculate_nickels(int cents)
{
    int n; //Stores the number of nickels
    for (n = 0; cents / 5 > 0; cents -= 5)
    {
        n += 1;
    }
    return n;
}

int calculate_pennies(int cents)
{
    int p; //Stores the number of nickels
    for (p = 0; cents > 0; cents -= 1)
    {
        p += 1;
    }
    return p;
}
