#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// prototypes
int get_points(string s);

const char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
    'U', 'V', 'W', 'X', 'Y', 'Z'};

const int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8,
  5, 1, 3, 1, 1, 3, 10, 1, 1, 1,
  1, 4, 4, 8, 4, 10};

int main(void)
{

    string input1 = get_string("Player 1: ");
    string input2 = get_string("Player 2: ");

    int first = get_points(input1);
    int sec = get_points(input2);

    if (first > sec)
    {
        printf("Player 1 wins!\n");
    }
    else if (sec > first)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int get_points(string s)
{
    int sum_points = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        int counter = 0; // ascii = 'A'
        if (isalpha(s[i]))
        {
            while (toupper(s[i]) != letters[counter])
            {
                counter++;
            }
            sum_points += points[counter];
        }
    }

    return sum_points;
}
