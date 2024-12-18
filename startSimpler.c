#include <stdio.h>
#include <string.h>
#include <stdarg.h>
// plan is to use putc() or putchar() to take a char at a time and put them into a list which will ultimately be printed
// loop through the first parameter and get each char into an array
// put them to stdout
// maybe use ascii to help with identifiers?


// next step: if encounter % then go to a section that asks if is %d, %x, %c, or %s and do different things based on that
// if %d then need to add to the array as a decimal

void my_printf(char *phrase, ...) {
    va_list ap; // initialize list for variables
    va_start(ap, phrase);
    while (*phrase != '\0') {
        if (*phrase == '%') {
            // move to the next character to get type
            phrase++;
            if (*phrase == 'd') {
                int num = va_arg(ap, int); // get the next argument
                // cast it into an int
                int ascii = (int) num;
                
                // sizes can only be 10 places anyway
                char str[12]; // later want to turn the int into a str to print each digit individually
                int index = 0;
                
                // turn the into a string, but backwards
                while (ascii > 0) {
                    int temp = ascii % 10;
                    //printf("%d", temp);
                    // add this digit to the string
                    str[index] = '0' + temp;
                    index++;
                    // get rid of last digit
                    ascii /= 10;
                }
                // add a teminal char
                //str[index] = '\0';
                //index++;
                
                // now need to putchar() the chars - backwards
                for (int i = index-1; i >= 0; i--) {
                    //printf("here");
                    putchar(str[i]);
                }
            }
        }
        else {
            putchar(*phrase);
        }
        phrase++;
    }
    va_end(ap); // cleanup the va_list
}

int main() {
    printf("Normal printf(): ");
    printf("Hello World %d\n", 82);

    printf("Fake printf(): ");
    my_printf("Hello World %d\n", 82);

    printf("Normal printf(): ");
    printf("Hello World %d\n", 'f');

    printf("Fake printf(): ");
    my_printf("Hello World %d\n", 'f');



    return 0;
}