// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    // fread(ZIEL, ELEMENT-GRÖSSE, ANZAHL, DATEI);
    unsigned char header[HEADER_SIZE]; // = ZIEL
    size_t read = fread(header, 1, HEADER_SIZE, input);

    // fwrite(QUELLE, ELEMENT-GRÖSSE, ANZAHL, DATEI);
    fwrite(header, 1, HEADER_SIZE, output); // schreibt den header in output

    // TODO: Read samples from input file and write updated data to output file
    unsigned char sample[2];
    while (fread(sample, 1, 2, input) == 2)
    {
        short *value = (short *) sample;
        *value *= factor;
        fwrite(value, 1, 2, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
