#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{

    // Check usage
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open memory card file
    FILE *image = fopen(argv[1], "r");
    if (!image)
    {
        printf("Could not open the file.\n");
        return 1;
    }

    //Assign NULL to a new JPEG file
    FILE *new = NULL;

    //Declare filename for new JPEG files
    char filename[8];

    // Count image
    int count_image = 0;

    //Read through block_size of bytes in memory card file
    BYTE bytes[BLOCK_SIZE];

    //Make fread function loop until left with not enough bytes
    while (fread(bytes, sizeof(BYTE), BLOCK_SIZE, image) == BLOCK_SIZE)
    {
        //Look for beginning of a JPEG
        if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
        {
            if (count_image == 0)
            {
                //Number the files it outputs by naming
                sprintf(filename, "%03i.jpg", count_image);

                //Open a new JPEG file
                new = fopen(filename, "w");

                //Write 512 bytes until a new JPEG is found
                fwrite(bytes, sizeof(BYTE), BLOCK_SIZE, new);

                // Add filename counter
                count_image++;
            }
            else if (count_image > 0)
            {
                // Close current writing file
                fclose(new);

                // Generate a sequence name for a new file
                sprintf(filename, "%03i.jpg", count_image);

                // Open a new JPEG file
                new = fopen(filename, "w");

                //Write 512 bytes to the new file
                fwrite(bytes, sizeof(BYTE), BLOCK_SIZE, new);

                //Add filename counter
                count_image++;
            }
        }
        // Keep writing to the same filename if a new JPEG is not found
        else if (count_image > 0)
        {
            fwrite(bytes, sizeof(BYTE), BLOCK_SIZE, new);
        }
    }
    //Stop at the end of the file
    fclose(image);
    fclose(new);
}