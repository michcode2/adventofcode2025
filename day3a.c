#include <stdlib.h>
#include <stdio.h>

int real_strlen(char *string);

int main(void){
    FILE *f;
    char* this_line;
    int idx_tens;
    int acc = 0;
    int i;
    int biggest_tens = 0;
    int biggest_units = 0;

    this_line = malloc(100);
    f = fopen("./input3.txt", "r");

    while (fscanf(f, "%s\n", this_line)>0) {
        biggest_tens = 0;
        biggest_units = 0;
        for (i = 0; i < real_strlen(this_line)-1; i++) {
            if (this_line[i] - '0' > biggest_tens) {
                biggest_tens = this_line[i] - '0';
                idx_tens = i;
            }
        }

        for (i = idx_tens+1; i < real_strlen(this_line); i++) {
            if (this_line[i] - '0' > biggest_units) {
                biggest_units = this_line[i] - '0';
            }
        }
        printf("%d\n", biggest_tens*10 + biggest_units);
        acc += biggest_tens * 10;
        acc += biggest_units;
    }
    printf("%d\n", acc);
}

int real_strlen(char *string) {
    int len = 0;

    while (string[len] != 0){
        len++;
    }
    return len;
}
