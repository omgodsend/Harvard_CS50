#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct
{
    uint8_t BYTE;
}
byte;

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");

    if (argc != 2 || *file == NULL)
    {
        printf("ERR. Enter valid file\n")
        return 1
    }

    char filename

    byte *buffer = malloc(sizeof(byte) * 64);
    if (buffer == NULL)
    {
        printf("Error: Could not allocate memory");
        return 1;
    }

    int file_count = 0;

    while (fread(buffer, 1, sizeof(byte), 64, file) == 64)
    {
        if (buffer[0].BYTE == 0xff && buffer[1].BYTE == 0xd8 && buffer[2].BYTE == 0xff && ((buffer[3].BYTE & 0xf0) == 0xe0))
        {
            sprintf(filename, "%03i.jpg", file_count);
            file_count++;

            FILE *img = fopen(filename, "a");
            fwrite(data, size, number, outputr);
        }
        else
        {
            fclose(file)

        }


    }




}