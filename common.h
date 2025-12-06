#include <stdio.h>

typedef struct {
    int columns;
    int rows;
    char** data;
} grid;

void print_grid(grid thisgrid) {
    int x = 0;
    int y = 0;
    for (y=0; y < thisgrid.rows; y++) {
        for (x=0; x < thisgrid.columns; x++){
            printf("%d", thisgrid.data[x][y]);
        }
        printf("\n");
    }
}

int real_strlen(char *string) {
    int len = 0;

    while (string[len] != 0){
        len++;
    }
    return len;
}
