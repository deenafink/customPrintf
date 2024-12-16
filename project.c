#include <stdio.h>
// plan is to use putc() or putchar() to take a char at a time and put them into a list which will ultimately be printed
// loop through the first parameter and get each char into an array
// put them to stdout
// maybe use ascii to help with identifiers?

void my_printf(char *phrase) {
    char preview[100];
    int index = 0;

    // add to the buffer
    while (*phrase != '\0') {
        preview[index] = *phrase;
        phrase++;
        index++;
    }

    // terminate the phrase
    

    // putchar them to stout
    for (int i=0; i<index; i++) {
        putchar(preview[i]);
    }
}

int main()
{
    printf("Normal printf(): ");
    printf("Hello World\n");

    printf("Fake printf(): ");
    my_printf("Hello World\n");

    return 0;
}