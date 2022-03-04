#include <stdio.h>
#include <stdlib.h>

struct slika {
    int x;
    int y;
    unsigned char* pixels;
};

/*int main(int argc, char* argv[]) {

    struct slika pic;
    FILE *input = fopen(argv[1], "rb");
    char skip[10];

    fscanf(input, "%s\n", skip);
    fscanf(input, "%d\n", &pic.x);
    fscanf(input, "%d\n", &pic.y);
    fscanf(input, "%s\n", skip);

    int rezolucija = pic.x * pic.y;
    pic.pixels = malloc(sizeof(unsigned char) * rezolucija);
    fread(pic.pixels, sizeof(unsigned char), rezolucija, input);

    int brojac[16];
    int i;
    for (i = 0; i < 16; ++i) brojac[i] = 0;
    for (i = 0; i < rezolucija; ++i) ++brojac[pic.pixels[i] >> 4];

    for(i = 0; i < 16; ++i) printf("%d %d\n", i, brojac[i]);
    return 0;
}
*/
