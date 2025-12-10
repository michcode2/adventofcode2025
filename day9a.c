#include <stdlib.h>
#include <stdio.h>

typedef struct {
    long x;
    long y;
} Polong;

long absl(long a) {
    if (a > 0) {
        return a;
    }
    return -1 * a;
}

int main(void) {
    FILE *f = fopen("input9.txt",  "r");
    long i = 0;
    long j = 0;
    Polong *p;
    Polong temp_polong;
    long temp_x;
    long temp_y;
    long num_polongs = 0;
    long max_area = 0;
    long dx;
    long dy;

    p = malloc(5000 * sizeof(Polong *));


    while (!feof(f)) {
        fscanf(f, "%ld,%ld",&temp_x, &temp_y);
        printf("reading %ld, %ld\n", temp_x, temp_y);
        p[i] = (Polong){temp_x, temp_y};
        i++;
    }
    num_polongs = i;
    printf("polongs: %ld\n", num_polongs);

    for (i = 0; i < num_polongs; i++) {
        for (j = 0; j < num_polongs; j++) {
            dx = absl(p[i].x - p[j].x) + 1;
            dy = absl(p[i].y - p[j].y) + 1;

            printf("(%ld, %ld) (%ld, %ld) %ld\n", p[i].x, p[i].y, p[j].x, p[j].y,  dy * dx);

            if (dx * dy > max_area) {
                max_area = dx * dy;
            }
        }
    }

    printf("%ld, %ld\n", max_area, num_polongs);

}
