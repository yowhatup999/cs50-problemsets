#include <cs50.h>
#include <stdio.h>

int main(void)
{

    // only accept 1 - 8 height or redo input
    int height;
    int og_height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    og_height = height;
    int current_row = 1;

    int i;
    // for loop für pyramiden größe
    for (i = 0; i < height; i++)
    {
        // for loop für jede zeile
        for (int j = 0; j < (height - current_row); j++)
        {
            printf(" ");
        }
        // für hashes
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        current_row++;
        printf("\n");
    }

    return 0;
}
