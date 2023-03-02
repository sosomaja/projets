#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("usage: ./recover 'filename'\n");
        return 1;
    }
    char *fname = argv[1];
    FILE *infile = fopen(fname, "r");
    if (infile == NULL)
    {
        printf("file not found or corrupted\n");
        return 1;
    }
    int idx = 0;
    uint8_t buffer[512];
    char filename[9];
    FILE *ptr;
    while (fread(buffer, 1, 512, infile) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg", idx);
            if (idx == 0)
            {
                ptr = fopen(filename, "w");
            }
            else
            {
                fclose(ptr);
                ptr = fopen(filename, "w");
            }
            idx++;
        }
        if (ptr != NULL)
        {
            fwrite(buffer, 1, 512, ptr);
        }
    }
    fclose(ptr);
    fclose(infile);
    printf("recovered %i jpg files\n", idx);
}