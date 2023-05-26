//This is a problem of week1
//hello.c

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("what's your name?");
    printf("hello, %s\n", name);
}
