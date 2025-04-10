#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage - /fileName CardPath\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    unsigned char buffer[512];
    int fileCount = 0;

    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = NULL; // output file vorbereiten

    while (fread(buffer, 1, 512, file) == 512)
    {
        char filename[8]; // später für filename platz machen

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (output != NULL)
            {
                fclose(output); // falls header gefunden und file ist geschrieben
            }

            sprintf(filename, "%03i.jpg", fileCount); // füllt den filename string
            output = fopen(filename, "wb");

            if (output == NULL)
            {
                printf("Could not open file.\n");
                return 1;
            }

            // hier schreiben wir den ersten block
            fwrite(buffer, 1, 512, output);
            fileCount++;
        }
        else if (output != NULL)
        {
            fwrite(buffer, 1, 512, output);
        }
    }
    fclose(output);
    fclose(file);
}
