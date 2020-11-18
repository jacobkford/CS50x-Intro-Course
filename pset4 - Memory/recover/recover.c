#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// States the buffer size
#define BUFFER_SIZE 512

// Creates the 'Byte' data type
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Checks for correct argument input
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover .raw\n");
        return 1;
    }

    // Open file
    FILE *file = fopen(argv[1], "r");
    // If the program cannot open file
    if (file == NULL)
    {
        fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
        return 2;
    }
    // Creates image file pointer
    FILE *img = NULL;
    // Creates the buffer to store 512 bytes
    BYTE *buffer = malloc(BUFFER_SIZE);
    // Initialising JPEG count for when the file search starts
    int jpeg_count = 0;
    // Initialises filename for writing
    char file_name[8];

    // Repeats until the end of the file
    while (fread(buffer, BUFFER_SIZE, 1, file))
    {
        // Checks if buffer starts with the JPEG signature pattern in the first 4 bytes
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Checks if a jpeg file is open already
            if (jpeg_count > 0)
            {
                fclose(img);
            }

            // Creates the file for the jpeg & opens it
            sprintf(file_name, "%03d.jpg", jpeg_count);
            img = fopen(file_name, "w");

            if (img == NULL)
            {
                fclose(file);
                free(buffer);
                fprintf(stderr, "Could not create file %s", file_name);
                return 3;
            }
            // Updates jpeg count
            jpeg_count++;
        }
        // Checks if there is a current jpeg file that exists
        if (jpeg_count > 0)
        {
            // Writes buffer to the jpeg file
            fwrite(buffer, BUFFER_SIZE, 1, img);
        }
    }
    // Closes image file
    fclose(img);
    // Close the file
    fclose(file);
    // Free memory from the buffer
    free(buffer);
    // Ends program
    return 0;
}
