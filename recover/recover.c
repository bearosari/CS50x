#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    // checking the filename if specified
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // checking if memory card opening was a success
    FILE *file = fopen(argv[1], "r");
    // error handling of uncessful card reading
    if (file == NULL)
    {
        fprintf(stderr, "Could not open file %s.\n", argv[1]);
        return 1;
    }

    //create vars that we gonna use and allocate memory for them
    FILE *image;
    char filename[7];
    unsigned char *buffer = malloc(512);
    int count = 0;

    while (fread(buffer, 512, 1, file))
    {
        // new jpg file found
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (count > 0)
            {
                fclose(image);
            }

            // creating new file
            sprintf(filename, "%03d.jpg", count);
            // opening  new image file
            image = fopen(filename, "w");

            // checking if jpg file is successfully created
            if (image == NULL)
            {
                fclose(file);
                free(buffer);
                fprintf(stderr, "Could not create output JPG %s", filename);
                return 3;
            }

            count++;
        }

        if (count > 0)
        {
            fwrite(buffer, 512, 1, image);
        }
    }

    //emptying memory and closing file as good practice
    fclose(image);
    fclose(file);
    free(buffer);
    return 0;
}
