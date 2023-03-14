#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("ERR. Enter valid file\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error: Could not open file %s.\n", argv[1]);
        return 1;
    }

    byte *buffer = malloc(sizeof(byte) * 64);
    if (buffer == NULL)
    {
        printf("Error: Could not allocate memory");
        fclose(file);
        return 1;
    }

    char *newfile = malloc(sizeof(char) * 12);
    if (newfile == NULL) {
        printf("Error: Could not allocate memory.\n");
        free(buffer);
        fclose(file);
        return 1;
    }

    int file_count = 0;

    while (fread(buffer, 1, 512, file) == 512)
    {
        if (buffer[0].BYTE == 0xff && buffer[1].BYTE == 0xd8 && buffer[2].BYTE == 0xff && ((buffer[3].BYTE & 0xf0) == 0xe0))
        {
            for (i = 0; i < sizeof(buffer); i++)
            {
                sprintf(newfile, "%03i.jpg", file_count);
                file_count++;

                FILE *img = fopen(newfile, "a");
                if (img == NULL)
                {
                    printf("Error: Could not open output file %s.\n", newfile);
                    free(buffer);
                    free(newfile);
                    fclose(file);
                    return 1;
                }

                if (img != NULL)
                {
                    fwrite(buffer, 1, sizeof(img), img);

                    if (buffer[0].BYTE == 0xff && buffer[1].BYTE == 0xd8 && buffer[2].BYTE == 0xff && ((buffer[3].BYTE & 0xf0) == 0xe0))
                    {
                        fclose(img);
                        img = NULL;
                    }
                }
            }
        }
    }

    free(buffer);
    free(newfile);
    fclose(file);

    return 0;
}
