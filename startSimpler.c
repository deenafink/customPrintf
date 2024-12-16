#include <stdio.h>
#include <string.h>
// plan is to use putc() or putchar() to take a char at a time and put them into a list which will ultimately be printed
// loop through the first parameter and get each char into an array
// put them to stdout
// maybe use ascii to help with identifiers?


// next step: if encounter % then go to a section that asks if is %d, %x, %c, or %s and do different things based on that
// if %d then need to add to the array as a decimal

void my_printf(char *phrase, int nums) {
    while (*phrase != '\0') {
        if (*phrase == '%') {
            // move to the next character to get type
            phrase++;
            if (*phrase == 'd') {
                char str[12]; // later want to turn the int into a str
                sprintf(str, "%d", nums); // int to string
                // now need to putchar() the chars
                for (int i = 0; str[i] != '\0'; i++) {
                    putchar(str[i]);
                }
            }
        }
        else {
            putchar(*phrase);
        }
        phrase++;
    }
}

int main() {
    printf("Normal printf(): ");
    printf("Hello World %d\n", 82);

    printf("Fake printf(): ");
    my_printf("Hello World %d\n", 82);

    return 0;
}