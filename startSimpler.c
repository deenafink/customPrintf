#include <stdio.h>
//#include <string.h>
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
            phrase++; // to get the flag or modifier or type...
            // %[flags][width][.precision][length]type
            // flags are -, +, , 0, ', #
            int plus_flag = 0;
            if (*phrase == '+') {
                plus_flag = 1;
                phrase++;
            }

            // width field the number is the minimum number of chars in output
            // get the number to be used later
            int width = 0;
            // first check if is a star (*), if so- get the next argument
            if (*phrase == '*') {
                width = va_arg(ap, int);
                phrase++;
            }

            // gets the number in a char form, need it in int to interpret how many
            while (*phrase >= '0' && *phrase <= '9') {
                // get the int 
                width = (width * 10) + *phrase - '0';
                phrase++;
            }

            if (*phrase == 'd') {
                int num = va_arg(ap, int); // get the next argument
                // cast it into an int
                int ascii = (int) num;
                // sizes can only be 10 places anyway
                char str[12]; // later want to turn the int into a str to print each digit individually
                int index = 0;

                // edge case of 0
                if (ascii == 0) {
                    str[index] = '0';
                    index++;
                }

                // if negative number
                if (ascii < 0) {
                    putchar('-');
                    ascii *= -1;
                }
                // if positive number and the + flag is there
                else {
                    if (plus_flag == 1)
                        putchar('+');
                }
                
                // turn the into a string, but backwards
                while (ascii > 0) {
                    int temp = ascii % 10;
                    // add this digit to the string
                    str[index] = '0' + temp;
                    index++;
                    // get rid of last digit
                    ascii /= 10;
                }
                // add a teminal char
                //str[index] = '\0';
                //index++;
                
                // over here need to check how many less than width and then put blank spaces
                if (index<width) {
                    int width_min = width-index;
                    for (int i=0; i<width_min; i++) {
                        putchar(' ');
                    }
                }

                // now need to putchar() the chars - backwards
                for (int i = index-1; i >= 0; i--) {
                    //printf("here");
                    putchar(str[i]);
                }
            }
            // prints it as a char
            // error if more than one character
            // error if not an ascii char
            if (*phrase == 'c') {
                char character = va_arg(ap, int); // get the next argument, the parameter is an int idk why can ask that
                // deal with width here
                for (int i=0; i<width-1; i++)
                    putchar(' ');
                putchar(character);
            }
            // s should be the same thing just multiple character so will move through it and print one by one
            if (*phrase == 's') {
                char *string = va_arg(ap, char*); // get the next argument
                char *copy = string;

                // get length of the string
                int len = 0;
                while (*string != '\0') {
                    len++;
                    string++;
                }
                //restore the pointer to the original point in memory
                string = copy;

                // insert the spaces for width
                if (width > len) {
                    int diff = width-len;
                    for (int i=0; i<diff; i++)
                        putchar(' ');
                }
                // add the letters now
                while (*string != '\0') {
                    putchar(*string);
                    string++;
                }
            }
                
            // if x: unsigned int as a hexadecimal number. x uses lower-case letters and X uses upper-case. could be similar to d
            // use 16 instead of 10
            // right now not working fully
            if (*phrase == 'x') {
                unsigned int unsigned_int = va_arg(ap, int); // get the next argument, the parameter is an int idk why can ask that
                
                // sizes can only be 10 places anyway
                char str[12]; // later want to turn the int into a str to print each digit individually
                int index = 0;

                // edge case of 0
                if (unsigned_int == 0) {
                    str[index] = '0';
                    index++;
                }
                // have a list of the hex digits
                char hex[16] = "0123456789abcdef";
                // turn the into a string, but backwards
                while (unsigned_int > 0) {
                    int temp = unsigned_int % 16;
                    // add this digit to the string
                    str[index] = hex[temp];
                    index++;
                    // get rid of last digit
                    unsigned_int /= 16;
                }

                // over here need to check how many less than width and then put blank spaces
                if (index<width) {
                    int width_min = width-index;
                    for (int i=0; i<width_min; i++) {
                        putchar(' ');
                    }
                }
                
                // now need to putchar() the chars - backwards
                for (int i = index-1; i >= 0; i--) {
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
    // printf("Normal printf(): ");
    // printf("Hello World %d\n", 10001);

    // printf("Fake printf(): ");
    // my_printf("Hello World %d\n", 10001);

    // printf("Normal printf(): ");
    // printf("Hello World %d what is your age %d\n", 'f', 3);

    // printf("Fake printf(): ");
    // my_printf("Hello World %d what is your age %d\n", 'f', 3);

    // printf("Normal printf(): ");
    // printf("Hello World %d\n", 0);

    // printf("Fake printf(): ");
    // my_printf("Hello World %d\n", 0);

    // printf("Normal printf(): ");
    // printf("Hello World %d\n", -55);

    // printf("Fake printf(): ");
    // my_printf("Hello World %d\n", -55);

    // printf("Normal printf(): ");
    // printf("Hello World %+d\n", 55);

    // printf("Fake printf(): ");
    // my_printf("Hello World %+d\n", 55);

    // // c
    // printf("Normal printf(): ");
    // printf("Hello World %c\n", 'c');

    // printf("Fake printf(): ");
    // my_printf("Hello World %c\n", 'c');

    // // s
    // printf("Normal printf(): ");
    // printf("Hello World %s\n", "string");

    // printf("Fake printf(): ");
    // my_printf("Hello World %s\n", "string");

    // // trying all of them together
    // printf("Normal printf(): ");
    // printf("This is a: %s, This is a number: %d, This is a char: %c\n", "string", 4, 'c');

    // printf("Fake printf(): ");
    // my_printf("This is a: %s, This is a number: %d, This is a char: %c\n", "string", 4, 'c');

    // // x
    // printf("Normal printf(): ");
    // printf("Hello World %x\n", 26);

    // printf("Fake printf(): ");
    // my_printf("Hello World %x\n", 26);

    // printf("Normal printf(): ");
    // printf("Hello World %x\n", 689);

    // printf("Fake printf(): ");
    // my_printf("Hello World %x\n", 689);

    printf("Normal printf(): \n");
    printf("Hello World %10d whats up\n", 689);

    printf("Fake printf(): \n");
    my_printf("Hello World %10d whats up\n", 689);

    printf("Normal printf(): \n");
    printf("Hello World %d\n", 689);

    printf("Fake printf(): \n");
    my_printf("Hello World %d\n", 689);

    printf("Normal printf(): \n");
    printf("Hello World %10c\n", 'f');

    printf("Fake printf(): \n");
    my_printf("Hello World %10c\n", 'f');

    printf("Normal printf(): \n");
    printf("Hello World %10s\n", "face");

    printf("Fake printf(): \n");
    my_printf("Hello World %10s\n", "face");

    // width with x
    printf("Normal printf(): \n");
    printf("%10x\n", 90);

    printf("fake printf(): \n");
    my_printf("%10x\n", 90);

    // checking with the star*
    printf("Normal printf(): \n");
    printf("%*d\n", 3, 10);

    printf("fake printf(): \n");
    my_printf("%*d\n", 3, 10);

    return 0;
}