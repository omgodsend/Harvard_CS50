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
        fprintf("Error: Could not open %s.\n", argv[1]);
        return 2;
    }

    FILE* newfile = NULL;

    int jpg_count = 0;

    BYTE buffer[512];

    char filename[8]={0};

    while (fread(buffer, sizeof(BYTE)* 512, 1, file) == 1)
    {
        if (buffer[0].BYTE == 0xff && buffer[1].BYTE == 0xd8 && buffer[2].BYTE == 0xff && ((buffer[3].BYTE & 0xf0) == 0xe0))
        {
            if (newfile != NULL)
            {
                fclose(newfile)
            }



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
