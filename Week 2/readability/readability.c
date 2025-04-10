#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// prototype
int get_grade(string s);
int get_letters(string s);
int get_words(string s);
int get_sentence(string s);
float get_avg_letter_per_100(string s);
float get_avg_sentence_per_100(string s);

int main(void)
{

    string input = get_string("Text: ");

    int final = get_grade(input);

    if (final < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (final > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", final);
    }
}

// return grade 1 to 16 (if > 16 then return "Grade 16+" and if under 1 return "Before Grade 1")
int get_grade(string s)
{
    int grade = 0;
    int letter_avg = get_letters(s);
    int sentence_avg = get_words(s);
    // Formel: index = 0.0588 * L - 0.296 * S - 15.8
    // L = average numbers of letter per 100
    // S = average numbers of sentences per 100

    // werte per 100
    float letters_per_100 = get_avg_letter_per_100(s);
    float sentence_per_100 = get_avg_sentence_per_100(s);
    // Formel eingesetzt
    float index = (0.0588 * letters_per_100 - 0.296 * sentence_per_100 - 15.8);

    grade = round(index);

    return grade;
}

// gibt die anzahl der buchstaben zurück
int get_letters(string s)
{
    int letter_count = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]))
        {
            letter_count++;
        }
    }

    return letter_count;
}

// gibt die anzahl der wörter zurück
int get_words(string s)
{
    int word_count = 1;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isblank(s[i]))
        {
            word_count++;
        }
    }

    return word_count;
}

// gibt die anzahl der sätze wieder
int get_sentence(string s)
{
    int sentence_count = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentence_count++;
        }
    }

    return sentence_count;
}

// calculate average letters per 100 words
float get_avg_letter_per_100(string s)
{
    float letters = get_letters(s);
    float words = get_words(s);
    float letter_per_100 = letters / words;

    return letter_per_100 * 100.0;
}

// calculate average sentence per 100 words
float get_avg_sentence_per_100(string s)
{
    float sentence = get_sentence(s);
    float words = get_words(s);
    float sentence_per_100 = sentence / words;

    return sentence_per_100 * 100.0;
}
