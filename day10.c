#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int light_pattern[100];
    int num_lights;
    int *button_affects;
    int light_state[100];
} Lights;

typedef enum {
    Idk,
    Target_pattern,
    Button,
    Button_list,
} Reading_state;

int main(void) {
    FILE *f = fopen("test10.txt", "r");
    Lights lights[10];
    char current = 0;
    int temp_buttons = 0;
    int temp_lights = 0;
    Lights temp_line = {};
    Reading_state state = Idk;

    while (!feof(f)) {
        current = fgetc(f);
        if (current == '[') {
            state = Target_pattern;
        } else if (current == ']') {

        }
    }
}
