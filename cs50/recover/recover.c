#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");

    typedef struct
    {
    uint8_t BYTE;
    }

    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        return 0;
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0)

    }

        fclose(file)


}