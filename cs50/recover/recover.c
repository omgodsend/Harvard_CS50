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
        printf("Error: Could not allocate memory")
        return 1;
    }

    while (fread(buffer, 1, sizeof(byte) * 64, file) == byte(64))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))
        {
            sprintf(filename, "%03i.jpg", 2)
            FILE *img = fopen(filename, "a")
            fwrite(data, size, number, outputr)
        }
        else
        {
            fclose(file)

        }


    }




}