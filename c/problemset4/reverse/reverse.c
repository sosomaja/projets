#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("usage: ./reverse input.wav output.wav\n");
        return 1;
    }
    // Open input file for reading
    // TODO #2
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        printf("file not found or corrputed\n");
        return 1;
    }
    // Read header
    // TODO #3
    WAVHEADER buffer;
    fread(&buffer, sizeof(WAVHEADER), 1, infile);
    // Use check_format to ensure WAV format
    // TODO #4
    if (check_format(buffer) == 0)
    {
        printf("input file is not a wav file\n");
        return 1;
    }

    // Open output file for writing
    // TODO #5
    FILE *outfile = fopen(argv[2], "w");
    if (outfile == NULL)
    {
        printf("please make sure ouput is a wav file\n");
        return 1;
    }
    // Write header to file
    // TODO #6
    fwrite(&buffer, sizeof(WAVHEADER), 1, outfile);
    // Use get_block_size to calculate size of block
    // TODO #7
    int n = get_block_size(buffer);
    const int x = ftell(infile);
    int y = 0;
    fseek(infile, -n, SEEK_END);
    // Write reversed audio to file
    // TODO #8
    BYTE buffer2[n];
    while (fread(buffer2, sizeof(BYTE), n, infile) == n && (ftell(infile) != x))
    {
        fwrite(buffer2, sizeof(BYTE), n, outfile);

        fseek(infile, -((n * 2) + y), SEEK_END);
        y += 4;
    }
    fclose(infile);
    fclose(outfile);
}

int check_format(WAVHEADER header)
{
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return 1;
    };
    return 0;
}

int get_block_size(WAVHEADER header)
{
    int bytesPerSample = header.bitsPerSample / 8;
    return bytesPerSample * header.numChannels;
}