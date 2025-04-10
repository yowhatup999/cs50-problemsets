#include <cs50.h>
#include <stdio.h>

void calcChecksum(long cc_number, int number_length, int card_type);

int main(void)
{
    long number = get_long("Number: \n");
    long og_number = number;

    // Länge der Kartennummer
    int number_length = 0;
    long temp = number;
    while (temp > 0)
    {
        number_length++;
        temp /= 10;
    }

    // ersten beide Ziffern für die Kartenerkennung
    long n_counter = og_number;
    int first_digit = 0;
    int sec_digit = 0;

    while (n_counter >= 100)
    {
        n_counter /= 10;
    }
    sec_digit = n_counter;
    first_digit = sec_digit / 10;

    // Prüfe Kartentyp anhand der ersten Ziffern und Länge
    if (number_length == 15 && (sec_digit == 34 || sec_digit == 37))
    {
        calcChecksum(og_number, number_length, 1); // AMEX
    }
    else if (number_length == 16 && (sec_digit >= 51 && sec_digit <= 55))
    {
        calcChecksum(og_number, number_length, 2); // MASTERCARD
    }
    else if ((number_length == 13 || number_length == 16) && first_digit == 4)
    {
        calcChecksum(og_number, number_length, 3); // VISA
    }
    else
    {
        printf("INVALID\n");
    }
}

void calcChecksum(long cc_number, int number_length, int card_type)
{
    long number_first = cc_number;
    long number_sec = cc_number;

    int calculated_first_step = 0;
    int sum_digits = 0;

    // Loop für jede zweite Ziffer von hinten (ab -2)
    number_sec /= 10;
    while (number_sec > 0)
    {
        int digit_sec_last = number_sec % 10;
        number_sec /= 100;

        int doubled = digit_sec_last * 2;
        if (doubled > 9)
        {
            calculated_first_step += (doubled / 10) + (doubled % 10);
        }
        else
        {
            calculated_first_step += doubled;
        }
    }

    // Loop für jede zweite Ziffer von hinten (ab -1)
    while (number_first > 0)
    {
        int digit_last = number_first % 10;
        number_first /= 100;
        sum_digits += digit_last;
    }

    // Summe berechnen
    sum_digits += calculated_first_step;

    // Prüfe Checksumme
    if (sum_digits % 10 == 0)
    {
        if (card_type == 1)
        {
            printf("AMEX\n");
            return;
        }
        else if (card_type == 2)
        {
            printf("MASTERCARD\n");
            return;
        }
        else if (card_type == 3)
        {
            printf("VISA\n");
            return;
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
