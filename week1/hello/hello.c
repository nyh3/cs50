#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What's your name? "); //Store name as a string
    printf("hello, %s\n", name);
}