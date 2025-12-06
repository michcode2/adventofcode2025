#include <stdio.h>
#include <stdlib.h>
#include "common.h"

/*
 * check commit time
 * 10 minutes for disruption
 */


int main(void) {
    FILE *f = fopen("input5.txt", "r");
    char* line = malloc(300*sizeof(char));
    int has_dash = 0;
    int i = 0;
    unsigned long highest_fresh=0;
    unsigned long bound_low=0;
    unsigned long bound_high=0;
    long *fresh_ids;
    int acc=0;


    while (!feof(f)){
        if (fscanf(f, "%ld-%ld\n", &bound_low, &bound_high)!= 2) {
            printf("break time\n");
            break;
        }
        printf("%ld-%ld\n", bound_low, bound_high);
        /* sscanf(line, "%ld-%ld\n", &bound_low, &bound_high); -------------- sscanf of shame*/
        if (bound_high > highest_fresh) {
            highest_fresh = bound_high;
            printf("new hightest fresh %ld\n", highest_fresh);
        }
    }

    printf("highest fresh found\n");
    fresh_ids=malloc((highest_fresh+1) * sizeof(long));
    rewind(f);


    for (i=0; i < highest_fresh; i++) {
        printf("%d, %ld\n", i, highest_fresh);
        fresh_ids[i]=0;
    }

    printf("starting to fill it out\n");

    while(fscanf(f, "%ld-%ld\n", &bound_low, &bound_high) > 0){
        sscanf(line, "%ld-%ld\n", &bound_low, &bound_high);
        for (i = bound_low; i <= bound_high; i++){
            fresh_ids[i] = 1;
        }
    }

    printf("populated fresh database");
    rewind(f);

    while(fscanf(f, "%s\n", line) > 0){
        has_dash = 0;
        for (i = 0; i < real_strlen(line); i++) {
            if (line[i] == '-') {
                has_dash = 1;
            }
        }
        if (has_dash==0) {
            sscanf(line, "%d\n",&i);
           if (fresh_ids[i] == 1){
               acc++;
               printf("%d is fresh\n", i);
           }
        }
    }

    printf("%d fresh ings\n", acc);
}
