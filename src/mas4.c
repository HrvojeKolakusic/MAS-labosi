#include <stdio.h>
#include <stdlib.h>

#define MAD_MAX 9999999

struct slika {
    int x;
    int y;
    unsigned char* pixels;
};

int main(int argc, char* argv[]) {

    FILE *slika1, *slika2;
    char skip[10];
    int i, j, a, b, x, y;
    struct slika pic1, pic2;

    slika1 = fopen("lenna.pgm", "rb");
    fscanf(slika1, "%s\n", skip);
    fscanf(slika1, "%d\n", &pic1.x);
    fscanf(slika1, "%d\n", &pic1.y);
    fscanf(slika1, "%s\n", skip);
    pic1.pixels = malloc(sizeof(unsigned char) * pic1.x * pic1.y);
    fread(pic1.pixels, sizeof(unsigned char), pic1.x * pic1.y, slika1);

    slika2 = fopen("lenna1.pgm", "rb");
    fscanf(slika2, "%s\n", skip);
    fscanf(slika2, "%d\n", &pic2.x);
    fscanf(slika2, "%d\n", &pic2.y);
    fscanf(slika2, "%s\n", skip);
    pic2.pixels = malloc(sizeof(unsigned char) * pic2.x * pic2.y);
    fread(pic2.pixels, sizeof(unsigned char), pic2.x * pic2.y, slika2);

    int inputX = (atoi(argv[1]) % 32) * 16;
    int inputY = (atoi(argv[1]) / 32) * 16;
    x = -16;
    y = -16;
    double mad = MAD_MAX;

    if (inputY - 16 < 0) i = 0;
    else i = inputY - 16;
    for(; i <= inputY + 16; ++i) {
        if(i + 16 > pic1.y) break;

        if (inputX - 16 < 0) j = 0;
        else j = inputX - 16;
        for(; j <= inputX + 16; ++j) {
            if(j + 16 > pic1.x) break;

            double currMad = 0;
            for(b = 0; b < 16; ++b) {
                for(a = 0; a < 16; ++a)
                    currMad += (double)abs(pic1.pixels[(i + b)*pic1.y + (j + a)]
										- pic2.pixels[(inputY + b)*pic2.x + inputX + a]) / 256;

            }

            if(currMad < mad) {
                mad = currMad;
                x = j - inputX;
                y = i - inputY;
            }
        }
    }

    printf("%d,%d\n", x, y);
    return 0;
}
