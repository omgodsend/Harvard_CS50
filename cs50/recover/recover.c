#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");

    if (argc != 1 || *file == NULL)
    {
        printf("ERR. Enter valid file\n")
        return 1
    }

    char *size = malloc(sizeof(*file) + 1);
    if (size == NULL)
    {
        return 1;
    }

    typedef struct
    {
    uint8_t BYTE;
    }
    byte;

    while (fread(buffer, 1, byte(64), file) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))
        {
            for (int i = 0; i < x; i++)
            sprint([i], "%03i.jpg", 2)
        }


        fclose(file)
    }




}