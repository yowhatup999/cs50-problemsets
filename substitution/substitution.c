#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// prototype
bool is_valid_key(string key);
string substitution(string s, string key);

int main(int argc, string argv[])
{
    // argc muss 2 sein

    // argv[1] muss 26 unique alphabetic characters haben!

    if (argc != 2)
    {
        printf("Usage: %s KEY\n", argv[0]);
        return 1;
    }
    if (is_valid_key(argv[1]))
    {
        // Do the substitution:
        string s = get_string("Plaintext:  ");
        string key = argv[1];
        char *ciphertext = substitution(s, key);
        printf("ciphertext: %s\n", ciphertext);
        free(ciphertext); // Speicher freigeben, um Leaks zu vermeiden
        return 0;
    }
    else
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
}

bool is_valid_key(string key)
{
    int check = 0;

    if (strlen(key) != 26)
    {
        return false;
    }

    // erstes loop checken auf buchstaben
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
        // zweites loop checke auf gleicheit des strings
        for (int j = i + 1; j < n; j++)
        {
            if (tolower(key[i]) == tolower(key[j]))
            {
                return false;
            }
        }
    }

    return true;
}

string substitution(string s, string key)
{
    int n = strlen(s);
    char *output = malloc(n + 1); // Speicherplatz für n Zeichen + Nullterminator

    // prüfung wegen malloc
    if (output == NULL) // Sicherheitsprüfung
    {
        printf("Speicher konnte nicht reserviert werden.\n");
        return NULL;
    }

    // erst checken upper OR lower + replace
    for (int i = 0; i < n; i++)
    {
        if (isalpha(s[i]))
        {
            if (isupper(s[i]))
            {
                int index = (s[i] - 'A');
                output[i] = toupper(key[index]);
            }
            else if (islower(s[i]))
            {
                int index = (s[i] - 'a');
                output[i] = tolower(key[index]);
            }
        }
        else
        {
            output[i] = s[i];
        }
    }
    output[n] = '\0';

    return output;
}
// NQXPOMAFTRHLZGECYJIUWSKDVB
