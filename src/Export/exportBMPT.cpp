#include "export.h"
#include <iostream>

namespace Export
{
    int exportBMP(struct pixel graph[V][H])
    {
        typedef struct                       /**** BMP file header structure ****/
        {
            unsigned int   bfSize;           /* Size of file */
            unsigned short bfReserved1;      /* Reserved */
            unsigned short bfReserved2;      /* ... */
            unsigned int   bfOffBits;        /* Offset to bitmap data */
        } bmpFileHeader;

        typedef struct                       /**** BMP file info structure ****/
        {
            unsigned int   biSize;           /* Size of info header */
            int            biWidth;          /* Width of image */
            int            biHeight;         /* Height of image */
            unsigned short biPlanes;         /* Number of color planes */
            unsigned short biBitCount;       /* Number of bits per pixel */
            unsigned int   biCompression;    /* Type of compression to use */
            unsigned int   biSizeImage;      /* Size of image data */
            int            biXPelsPerMeter;  /* X pixels per meter */
            int            biYPelsPerMeter;  /* Y pixels per meter */
            unsigned int   biClrUsed;        /* Number of colors used */
            unsigned int   biClrImportant;   /* Number of important colors */
        } bmpInfoHeader;

        bmpFileHeader bfh;
        bmpInfoHeader bih;

        /* Magic number for file. It does not fit in the header structure due to alignment requirements, so put it outside */
        unsigned short bfType=0x4d42;
        bfh.bfReserved1 = 0;
        bfh.bfReserved2 = 0;
        bfh.bfSize = 2+sizeof(bmpFileHeader) + sizeof(bmpInfoHeader)+640*480*3;
        bfh.bfOffBits = 0x36;

        bih.biSize = sizeof(bmpInfoHeader);
        bih.biWidth = H;
        bih.biHeight = V;
        bih.biPlanes = 1;
        bih.biBitCount = 24;
        bih.biCompression = 0;
        bih.biSizeImage = 0;
        bih.biXPelsPerMeter = 5000;
        bih.biYPelsPerMeter = 5000;
        bih.biClrUsed = 0;
        bih.biClrImportant = 0;

        FILE *file = fopen("graph.bmp", "wb");
        if (!file)
        {
            printf("Could not write file\n");
            return 1;
        }

        /*Write headers*/
        fwrite(&bfType,1,sizeof(bfType),file);
        fwrite(&bfh, 1, sizeof(bfh), file);
        fwrite(&bih, 1, sizeof(bih), file);

        /*Write bitmap*/
        for (int y = bih.biHeight-1; y>=0; y--) /*Rows loops backward*/
        {
            for (int x = 0; x < bih.biWidth; x++) /*Columns loops forward*/
            {
                fwrite(&graph[y][x].b, 1, 1, file);
                fwrite(&graph[y][x].g, 1, 1, file);
                fwrite(&graph[y][x].r, 1, 1, file);
            }
        }
        fclose(file);
        return 0;
    }
}
