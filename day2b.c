#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

long is_repeating(long test);
bool is_repeating_recursive(long test, int length) ;

int main(void) {
    long acc = 0;
    long id1;
    long id2;
    FILE *input = fopen("./test2.txt", "r");
    char* id;
    long i;

    id = malloc(100*sizeof(char));

    while(fscanf(input, "%ld-%ld,", &id1, &id2) == 2) {
        for (i = id1; i <= id2; i++) {
            acc += is_repeating(i);
        }
    }
    printf("\n\n\n%ld\n", acc);
}

long is_repeating(long test){
    char* as_string;
    long i;
    int halflen;

    as_string = malloc(100);
    sprintf(as_string, "%ld", test);

    halflen = strlen(as_string) / 2;
    for (i = strlen(); i <= strlen(as_string); i++) {
        printf("%d %d ", test, i);
        if (is_repeating_recursive(test, i)) {
            printf("yes\n");
            return test;
        }
        printf("no\n");
    }

    return 0;
}

bool is_repeating_recursive(long test, int length) {
    char* as_string;
    long i;
    int halflen;

    as_string = malloc(100);
    sprintf(as_string, "%ld", test);

    if (strlen(as_string)%length!=0) {
        return false;
    }
    halflen = strlen(as_string)/length;

    for (i = 0; i < halflen; i++) {
        if (as_string[i] != as_string[i + halflen]) {
            return 0;
        }
    }
    return true;
}
