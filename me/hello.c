#include <cs50.h>
#include <stdio.h>

int main(void) {
    string input = get_string("What´s your name?: \n");
    printf("hello, %s\n", input);
    return 0;
}
