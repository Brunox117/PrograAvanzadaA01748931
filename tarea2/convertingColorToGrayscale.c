#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
typedef struct {
   char id_len;                 // ID Field (Number of bytes - max 255)
   char map_type;               // Colormap Field (0 or 1)
   char img_type;               // Image Type (7 options - color vs. compression)
   int  map_first;              // Color Map stuff - first entry index
   int  map_len;                // Color Map stuff - total entries in file
   char map_entry_size;         // Color Map stuff - number of bits per entry
   int  x;                      // X-coordinate of origin 
   int  y;                      // Y-coordinate of origin
   int  width;                  // Width in Pixels
   int  height;                 // Height in Pixels
   char bpp;                    // Number of bits per pixel
   char misc;                   // Other stuff - scan origin and alpha bits
} targa_header;

void writeheader(targa_header *h, FILE *tga) {
   fputc(h->id_len, tga);          // Write chars for ID, map, and image type
   fputc(h->map_type, tga);
   fputc(h->img_type, tga);
   fputc(h->map_first % 256, tga); // Write integer, low order byte first
   fputc(h->map_first / 256, tga); // Write second byte of integer, high order
   fputc(h->map_len % 256, tga);   // Another integer 
   fputc(h->map_len / 256, tga);
   fputc(h->map_entry_size, tga);  // Write a char - only one byte
   fputc(h->x % 256, tga);         // More integers
   fputc(h->x / 256, tga);
   fputc(h->y % 256, tga);
   fputc(h->y / 256, tga);
   fputc(h->width % 256, tga);     // Even more integers
   fputc(h->width / 256, tga);
   fputc(h->height % 256, tga);
   fputc(h->height / 256, tga);
   fputc(h->bpp, tga);             // Write two chars
   fputc(h->misc, tga);
}

void readheader(targa_header *h, FILE *tga) {
   h->id_len = fgetc(tga);          // Write chars for ID, map, and image type
   h->map_type = fgetc(tga);
   h->img_type = fgetc(tga);
   h->map_first = fgetc(tga) + fgetc(tga)*256; 
   h->map_len = fgetc(tga) + fgetc(tga)*256;   // Another integer 
   h->map_entry_size = fgetc(tga);  // Write a char - only one byte
   h->x = fgetc(tga) + fgetc(tga)*256;
   h->y = fgetc(tga) + fgetc(tga)*256;
   h->width = fgetc(tga) + fgetc(tga)*256;
   h->height = fgetc(tga) + fgetc(tga)*256;
   h->bpp = fgetc(tga);             // Write two chars
   h->misc = fgetc(tga);
}

void prepareHeader(targa_header *header, int x, int y) {
   header->id_len = 0;          /* no ID field */
   header->map_type = 0;        /* no colormap */
   header->img_type = 2;        /* trust me */
   header->map_first = 0;       /* not used */
   header->map_len = 0;         /* not used */
   header->map_entry_size = 0;  /* not used */
   header->x = 0;               /* image starts at (0,0) */
   header->y = 0;
   header->width = x;
   header->height = y;
   header->bpp = 24;            /* 24 bits per pixel */
   header->misc = 0x20;         /* scan from upper left corner */	
}

int main(void) {
   FILE *tga;               // Pointer to a FILE
   targa_header header;     // Variable of targa_header type
   int x, y;				// Size of the image
   unsigned char *data;				// Array

   tga = fopen("Original.tga", "rb");
   readheader(&header, tga);  
   // Print size of the image
   printf("%d %d\n", header.width, header.height);
   data = (unsigned char*)malloc(header.width * header.height * 3);

	// Read data to the array
   fread(data, 3, header.width*header.height, tga);
   fclose(tga);

	// 2D iteration
   for(y = 0; y < header.height; y++)
      for(x = 0; x < header.width; x++) {
        unsigned char r, g, b, average;
        
        // Components for red, gree, and blue (inverted in targa)
        b = data[(y * header.width + x)*3 + 0];
        g = data[(y * header.width + x)*3 + 1];
        r = data[(y * header.width + x)*3 + 2];
        
        /* Aqu? modificar los valores de r, g, b */
        
        data[(y * header.width + x)*3 + 0] = b;
        data[(y * header.width + x)*3 + 1] = g;
        data[(y * header.width + x)*3 + 2] = r;
    }

	// Open output file
   tga = fopen("luminosityAlgoritmo.tga", "wb");
      
   writeheader(&header, tga);  
   for(y = 0; y < header.height; y++)
      for(x = 0; x < header.width; x++)	{
      	//luminosity
      	fputc((data[(y * header.width + x)*3 + 0] * 0.07 + data[(y * header.width + x)*3 + 1] * 0.72 + data[(y * header.width + x)*3 + 2] * 0.21), tga);
        fputc((data[(y * header.width + x)*3 + 0] * 0.07 + data[(y * header.width + x)*3 + 1] * 0.72 + data[(y * header.width + x)*3 + 2] * 0.21), tga);
        fputc((data[(y * header.width + x)*3 + 0] * 0.07 + data[(y * header.width + x)*3 + 1] * 0.72 + data[(y * header.width + x)*3 + 2] * 0.21), tga);
        //lightness
        //fputc(MAX(data[(y * header.width + x)*3 + 1],data[(y * header.width + x)*3 + 2]), tga);
        //fputc(data[(y * header.width + x)*3 + 1], tga);
        //fputc(data[(y * header.width + x)*3 + 2], tga);
	}

/* close the file */
   fclose(tga);

/* that was easy, right? */
   return 0;
}
