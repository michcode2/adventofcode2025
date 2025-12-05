#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "grid.h"

int cols_in_file(FILE *f);
int rows_in_file(FILE *f);
grid construct_grid(FILE* f);
void populate_grid(grid thisgrid, FILE* f);
int num_free_neighbours(grid thisgrid, int x, int y);

int main(void) {
    FILE *f = fopen("input4.txt", "r");
    grid thisgrid;
    int acc = 0;
    int x;
    int y;

    rewind(f);

    thisgrid = construct_grid(f);

    for (y = 0; y < thisgrid.rows; y++) {
        for (x=0; x < thisgrid.columns; x++) {
            if (num_free_neighbours(thisgrid, x, y) < 4) {
                acc++;
                thisgrid.data[x][y] = 3;
            }
        }
    }

    printf("\n\n\n");

    print_grid(thisgrid);

    printf("\n\n\n");

    printf("%d\n", acc);
    return 0;
}

int num_free_neighbours(grid thisgrid, int x, int y) {
    int acc=0;

    if (thisgrid.data[x][y] == 0) {
        return 9;
    }

    if (x>0) {
        if (y>0) {
            printf("TL ");
            if(thisgrid.data[x-1][y-1]>0) {
                acc+=1;
            }
        }
        if (y<thisgrid.rows){
            printf("L ");
            if(thisgrid.data[x-1][y]>0) {
                acc+=1;
            }
        }
        if (y<thisgrid.rows-1){
            printf("BL ");
            if(thisgrid.data[x-1][y+1]>0) {
                acc+=1;
            }
        }
    }

    {
        if (y>0) {
            printf("T ");
            if(thisgrid.data[x][y-1]>0) {
                acc+=1;
            }
        }
        if (y<thisgrid.rows-1){
            printf("B ");
            if(thisgrid.data[x][y+1]>0) {
                acc+=1;
            }
        }
    }

    if (x < thisgrid.columns-1) {
        if (y>0) {
            printf("TR ");
            if(thisgrid.data[x+1][y-1]>0) {
                acc+=1;
            }
        }
        if (y<thisgrid.rows){
            printf("R ");
            if(thisgrid.data[x+1][y]>0) {
                acc+=1;
            }
        }
        if (y<thisgrid.rows-1){
            printf("BR ");
            if(thisgrid.data[x+1][y+1]>0) {
                acc+=1;
            }
        }
    }

    printf("%d %d \n", x, y);

    return acc;
}


grid construct_grid(FILE* f) {
    int width = cols_in_file(f);
    int height = rows_in_file(f);
    char** data;
    int i;
    grid thisgrid;

    data = malloc(width * sizeof(char*));
    for (i = 0; i < height; i++) {
        data [i] = malloc(height * sizeof(char));
    }

    thisgrid.columns = width;
    thisgrid.rows = height;
    thisgrid.data = data;

    populate_grid(thisgrid, f);
    print_grid(thisgrid);

    return thisgrid;
}


void populate_grid(grid thisgrid, FILE* f) {
    int x = 0;
    int y = 0;
    char* line;

    line = malloc(100);

    rewind(f);

    for (y = 0; y < thisgrid.columns; y++) {
        fscanf(f, "%s\n", line);
        for (x = 0; x < thisgrid.rows; x++) {
            if (line[x] == '.'){
                thisgrid.data[x][y] = 0;
            } else {
                thisgrid.data[x][y] = 1;
            }
        }
    }
}

int cols_in_file(FILE *f) {
    int acc = 0;

    rewind(f);

    while (fgetc(f) != '\n') {
        acc++;
    }
    return acc;
}

int rows_in_file(FILE *f) {
    int acc = 0;
    char c;

    rewind(f);
    do {
        c = fgetc(f);
        if (c == '\n') {
            acc ++;
        }
    } while (c !=  EOF);
    return acc;
}
