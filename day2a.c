#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long is_repeating(long test);

int main(void) {
    long acc = 0;
    long id1;
    long id2;
    FILE *input = fopen("./input2.txt", "r");
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
    long halflen;
    long i;

    as_string = malloc(100);

    sprintf(as_string, "%ld", test);
    if (strlen(as_string)%2==1) {
        return 0;
    }
    halflen = strlen(as_string)/2;
    printf("\nv%s h%ld\t", as_string, halflen);

    for (i = 0; i < halflen; i++) {
        printf("%c, %c; ", as_string[i], as_string[i+halflen]);
        if (as_string[i] != as_string[i + halflen]) {
            return 0;
        }
    }
    printf("%ld is a yes", test);

    return test;

}
