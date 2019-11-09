// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"



int main(int argc, char *argv[])
{

    int n = atoi(argv[1]);
    if (n >= 100 || n <0)
     {
         return 1;
     }


    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    int inPadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }


     bi.biHeight *=n;
     bi.biWidth *=n;


    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

             // determine padding for scanlines

    int outPadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;


    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {

       for(int t=0 ; t<n ; t++)
        {
                    // iterate over pixels in scanline
                   for (int j = 0; j < bi.biWidth; j++)
                    {
                         // temporary storage
                         RGBTRIPLE triple;

                         // read RGB triple from infile
                         fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                         for(int m = 0 ; m < n ; m++ )
                            {
                                // write RGB triple to outfile
                                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                            }
                     }
                    // skip over padding, if any
                    fseek(inptr, inPadding, SEEK_CUR);

                    // then add it back (to demonstrate how)
                    for (int k = 0; k < outPadding; k++)
                    {
                        fputc(0x00, outptr);
                    }

                    fseek(inptr, -(bi.biWidth/n + inPadding) , SEEK_CUR);
        }

    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
