#include <stdio.h>

int main(int argc, char *argv[]) {
    char *filename;
    int width, height;
    double threshold;

    if (argc < 5) {
        printf("Usage: %s <filename> <width> <height> <threshold>\n", argv[0]);
        return 1;
    }

    filename = argv[1];
    width = atoi(argv[2]);
    height = atoi(argv[3]);
    threshold = atoi(argv[4]);

    // Print the captured values for verification
    printf("Filename: %s\n", filename);
    printf("Width: %d\n", width);
    printf("Height: %d\n", height);
    printf("Threshold: %lf\n", threshold);

    return 0;
}

