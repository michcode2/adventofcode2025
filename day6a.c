#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include <stdbool.h>
#include <string.h>

typedef enum {
    Add,
    Multiply
} Operation;

char** split(char *line);

int main(void) {
    FILE *f = fopen("test6.txt", "r");
    char *line;
    char** words;
    int i;

    line = malloc(1000);

    while (!feof(f)) {
        fgets(line, 1000, f);
        words = strtok(line, " ");

        for(i=0;i<4; i++) {
            printf("%s \n", words[i]);
        }

    }
}

char** split(char *line) {
    int alloc_length = 100;
    char** output = malloc(alloc_length);
    int i;
    char* temp_string;
    int word_index = 0;
    int on_space = false;
    int array_index = 0;

    temp_string = malloc(50);

    for (i=0; i<real_strlen(line); i++) {
        printf("%c ", line[i]);
        if (line[i] == ' ') {
            on_space = true;
            printf("space\n");
            continue;
        }
        if (on_space) {
            output[word_index] = temp_string;
            printf("%s \n", output[word_index]);
            temp_string = malloc(50);
            array_index = 0;
            printf("new word\n");
            on_space = false;
        }
        temp_string[array_index] = line[i];
        array_index++;
        printf("added to list\n");
    }
    return output;
}
