#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NUM_JOLTAGE 12

int real_strlen(char *string);

int main(void){
    FILE *f;
    char* this_line;
    long acc = 0;
    int i;
    int biggest_vals[NUM_JOLTAGE];
    int starting_indices[NUM_JOLTAGE + 1];
    int j;

    this_line = malloc(100);
    f = fopen("./input3.txt", "r");

    while (fscanf(f, "%s\n", this_line)>0) {
        for (i = 0; i < NUM_JOLTAGE; i++) {
            starting_indices[i] = 0;
            biggest_vals[i] = 0;
        }

        for (i = 0; i < NUM_JOLTAGE; i++) {
            for (j = starting_indices[i]; j < strlen(this_line) - (NUM_JOLTAGE-1-i) ; j++) {
                /*printf("%d, %d\n", this_line[j] - '0', biggest_vals[i])*/;
                if (this_line[j] - '0' > biggest_vals[i]) {
                    starting_indices[i+1] = j+1;
                    biggest_vals[i] = this_line[j] - '0';
                }
            }
            printf("%d", biggest_vals[i]);
        }
        printf("\n\n\n");

        for (i = 0; i < NUM_JOLTAGE; i++){
            acc += biggest_vals[i] * (long)pow(10, NUM_JOLTAGE - i - 1);
            printf("%ld\n", acc);
        }

    }
    printf("%ld\n", acc);
}

int real_strlen(char *string) {
    int len = 0;

    while (string[len] != 0){
        len++;
    }
    return len;
}
