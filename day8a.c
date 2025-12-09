#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define CONNECTIONS_TO_MAKE 10

typedef struct {
    int x;
    int z;
    int y;
} Point;

double distance(Point a, Point b);

int main(void) {
    FILE *f = fopen("test8.txt", "r");
    Point *points;
    int x;
    int y;
    int z;
    int i=0;
    int number_of_boxes;
    double shortest_connection = 1000000000000.0;
    int shortest_connection_a_index;
    int shortest_connection_b_index;
    int a;
    int b;


    points = malloc(2000 * sizeof(Point));

    while (!feof(f)) {
        fscanf(f, "%d,%d,%d\n", &x, &y, &z);
        points[i] = (Point){x, y, z};
        i++;
    }

    number_of_boxes = i;

    for (i=0; i < CONNECTIONS_TO_MAKE; i++) {
        shortest_connection = 1000000000000.0;
        shortest_connection_a_index = -1;
        shortest_connection_b_index = -1;
        for (a = 0; a < number_of_boxes; a++) {
            printf("%d, %d, %d\n", points[a].x, points[a].y, points[a].z);
        }

    }
}

double distance(Point a, Point b) {
    double acc  = 0;

    acc += pow((double)a.x, 2.0) + pow((double)a.x, 2.0);
    acc += pow((double)a.y, 2.0) + pow((double)a.y, 2.0);
    acc += pow((double)a.z, 2.0) + pow((double)a.z, 2.0);

    return pow(acc, 0.5);
}
