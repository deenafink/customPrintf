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

            // left alignment flag
            int left_alignment = 0;
            if (*phrase == '-') {
                left_alignment = 1;
                phrase++;
            }

            // zero flag
            int zeroes = 0;
            // check if 0 and then do zeros instead of spaces
            if (*phrase == '0') {
                zeroes = 1;
                phrase++;
            }

            // hash flag
            int hash_flag = 0;
            if (*phrase == '#') {
                hash_flag = 1;
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

            // gets the number in a char form, need it in int to interpret how many for width
            while (*phrase >= '0' && *phrase <= '9') {
                // get the int 
                width = (width * 10) + *phrase - '0';
                phrase++;
            }

            int precision = 0;
            // get the precision field
            if (*phrase == '.') {
                phrase++; // get the next which is either an int or a star
                if (*phrase == '*') { // if start get the next argument
                    precision = va_arg(ap, int);
                    phrase++;
                }
                else {
                    while (*phrase >= '0' && *phrase <= '9') {
                        // the current multiplied by 10 and then add in int
                        precision = (precision * 10) + *phrase - '0';
                        phrase++;
                    }
                }
            }


            if (*phrase == 'd') {
                int num = va_arg(ap, int); // get the next argument
                // cast it into an int
                int ascii = (int) num;
                int negative = 0;
                // sizes can only be 10 places anyway
                char str[12]; // later want to turn the int into a str to print each digit individually
                int index = 0;
                int length = 0;

                // edge case of 0
                if (ascii == 0) {
                    str[index] = '0';
                    index++;
                }

                // if negative number
                if (ascii < 0) {
                    //putchar('-');
                    negative = 1; // set negative to 1
                    ascii *= -1; // to turn the rest of the number positive
                }
                
                // turn the into a string, but backwards
                while (ascii > 0) {
                    int temp = ascii % 10;
                    // add this digit to the string
                    str[index] = '0' + temp;
                    index++;
                    // get rid of last digit
                    ascii /= 10;
                    length++;
                }
                
                // deal with precision
                if (precision > 0) {
                    //int diff = 0;
                    int totalWidth = length;
                    
                    // if the number of digits is less than the precision number, get the total number of chars needed with the extras added
                    if (length < precision) {
                        totalWidth += (precision-length);
                    }
                    // trying for left alignment
                    if (left_alignment == 1){
                        // since it gets entered backwards, this is where would add the positive or negative to the str
                        if (negative == 1) {
                            putchar('-');
                        }
                        if (plus_flag == 1 && negative == 0) {
                         putchar('+');
                        }     

                        // now need to place zeroes for precision
                        for (int i=0; i<(precision-length); i++) {
                            putchar('0');
                        }

                        // now need to putchar() the chars - backwards
                        for (int i = index-1; i >= 0; i--) {
                         putchar(str[i]);
                        }
                        
                        // now add the width padding
                        // over here need to check how many less than width and then put blank spaces
                        if (totalWidth<width) {
                            int width_min = width-totalWidth; // how many more spots need to be filled
                            // this is because the + and - take up a spot
                            if ((plus_flag == 1 && negative == 0) || negative==1)
                                width_min--;
                                // put the blank
                            for (int i=0; i<width_min; i++)
                                putchar(' ');
                        }    
                    }
                    // if it is deafult alignment
                    else {
                        // over here need to check how many less than width and then put blank spaces
                        if (totalWidth<width) {
                            int width_min = width-totalWidth; // how many more spots need to be filled
                            // this is because the + and - take up a spot
                            if ((plus_flag == 1 && negative == 0) || negative==1)
                                width_min--;
                            // put the blank
                            for (int i=0; i<width_min; i++)
                                putchar(' ');
                        }    

                        // since it gets entered backwards, this is where would add the positive or negative to the str
                        if (negative == 1) {
                            putchar('-');
                        }
                        if (plus_flag == 1 && negative == 0) {
                            putchar('+');
                        }     

                        // now need to place zeroes for precision
                        for (int i=0; i<(precision-length); i++) {
                            putchar('0');
                        }

                        // now need to putchar() the chars - backwards
                        for (int i = index-1; i >= 0; i--) {
                         putchar(str[i]);
                        }
                    }
                }

                // if precision isn't in the picture
                else {
                    
                    // need to check how many width spots are necessary
                    // if ((plus_flag == 1 && negative == 0) || negative==1) then need one less spot
                    if (left_alignment == 0) {
                        int width_min = width-index;
                        if ((plus_flag == 1 && negative == 0) || negative==1)
                            width_min--;

                        // if still needs spaces before putting the plus or minus
                        if (width_min>0) {
                            // if it is spaces not zeroes
                            if (zeroes == 0) {
                                for  (int i=0; i<width_min;i++)
                                    putchar(' ');
                        
                                if (negative == 1) {
                                    putchar('-');
                                }   
                                if (plus_flag == 1 && negative == 0) {
                                    putchar('+');
                                }  
                            }
                            // if zeroes instead of spaces
                            else {
                                if (negative == 1) {
                                    putchar('-');
                                }   
                                if (plus_flag == 1 && negative == 0) {
                                    putchar('+');
                                } 

                                for  (int i=0; i<width_min;i++)
                                    putchar('0');
                            }
                        }
                        // if don't need more spaces before, just put the sign
                        else {
                            if (negative == 1) {
                                    putchar('-');
                                }   
                                if (plus_flag == 1 && negative == 0) {
                                    putchar('+');
                                } 
                        }

                        // now need to putchar() the chars - backwards
                        for (int i = index-1; i >= 0; i--) {
                            putchar(str[i]);
                        }
                    } 
                    // left alignment
                    else {
                        int width_min = width-index;
                        if ((plus_flag == 1 && negative == 0) || negative==1)
                            width_min--;

                        
                        if (negative == 1) {
                             putchar('-');
                        }   
                        if (plus_flag == 1 && negative == 0) {
                            putchar('+');
                        } 
                        // now need to putchar() the chars - backwards
                        for (int i = index-1; i >= 0; i--) {
                            putchar(str[i]);
                        } 
                        for  (int i=0; i<width_min;i++)
                            putchar(' ');
                    }
                }
            }
            // prints it as a char
            // error if more than one character
            // error if not an ascii char
            if (*phrase == 'c') {
                char character = va_arg(ap, int); // get the next argument, the parameter is an int idk why can ask that
                // check if left alignment
                if (left_alignment == 1) {
                    putchar(character);
                    // deal with width here
                    for (int i=0; i<width-1; i++)
                        putchar(' ');
                }
                else {
                    // deal with width here
                    for (int i=0; i<width-1; i++)
                        putchar(' ');
                    putchar(character);
                }
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

                // if normal alignment
                // deal with precision
                if (left_alignment == 0) {
                    if (precision > 0) {
                        // width and precision together
                        if (width > precision) {
                            int diff = width-precision;
                            for (int i=0; i<diff; i++)
                                putchar(' ');
                        }
                    
                        int num = 0; // this is for precision
                        while (*string != '\0' && num < precision) {
                            putchar(*string);
                            string++;
                            num++;
                        }
                    }

                    // insert the spaces for width (without precision specified)
                    // update: check if width is greater than precision, not len
                    else {
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
                }
                else {
                    if (precision > 0) {
                        int num = 0; // this is for precision
                        while (*string != '\0' && num < precision) {
                            putchar(*string);
                            string++;
                            num++;
                        }
                        // width and precision together
                        if (width > precision) {
                            int diff = width-precision;
                            for (int i=0; i<diff; i++)
                                putchar(' ');
                        }
                    }

                    // insert the spaces for width (without precision specified)
                    // update: check if width is greater than precision, not len
                    else {
                        // add the letters now
                        while (*string != '\0') {
                            putchar(*string);
                            string++;
                        }
                        if (width > len) {
                            int diff = width-len;
                            for (int i=0; i<diff; i++)
                                putchar(' ');
                        }
                    }
                }
            } 
                
            // if x: unsigned int as a hexadecimal number. x uses lower-case letters and X uses upper-case. could be similar to d
            // use 16 instead of 10
            // right now not working fully
            if (*phrase == 'x' || *phrase == 'X') {
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

                 // check if # flag is set
                if (hash_flag == 1) {
                    str[index] = *phrase;
                    index++;
                    str[index] = '0';
                    index++;         
                }

                // deal with precision
                if (precision > 0) {
                    int totalWidth = index;
                    // if the number of digits is less than the precision number, add the difference in zeroes
                    // add that number to the index
                    if (index < precision) {
                        totalWidth += (precision-index);
                    }
                
                
                    // over here need to check how many less than width and then put blank spaces
                    if (totalWidth<width) {
                        int width_min = width-totalWidth;
                        for (int i=0; i<width_min; i++)
                            putchar(' ');
                    }         
                    // now need to place zeroes for precision
                    for (int i=0; i<(precision-index); i++) {
                        putchar('0');
                    }

                    // now need to putchar() the chars - backwards
                    for (int i = index-1; i >= 0; i--) {
                        //printf("here");
                        putchar(str[i]);
                    }
                }

                // over here need to check how many less than width and then put blank spaces
                else {
                    if (index<width) {
                        int width_min = width-index;
                        for (int i=0; i<width_min; i++) {
                            if (zeroes == 0)
                                putchar(' ');
                            else
                                putchar('0');
                        }
                    }

                    // now need to putchar() the chars - backwards
                    for (int i = index-1; i >= 0; i--) {
                        //printf("here");
                        putchar(str[i]);
                    }
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

    // printf("Normal printf(): \n");
    // printf("Hello World %10d whats up\n", 689);

    // printf("Fake printf(): \n");
    // my_printf("Hello World %10d whats up\n", 689);

    // printf("Normal printf(): \n");
    // printf("Hello World %d\n", 689);

    // printf("Fake printf(): \n");
    // my_printf("Hello World %d\n", 689);

    // printf("Normal printf(): \n");
    // printf("Hello World %10c\n", 'f');

    // printf("Fake printf(): \n");
    // my_printf("Hello World %10c\n", 'f');

    printf("Normal printf(): \n");
    printf("Hello World %10s\n", "face");

    printf("Fake printf(): \n");
    my_printf("Hello World %10s\n", "face");

    // // width with x
    printf("Normal printf(): \n");
    printf("%10x\n", 90);

    printf("fake printf(): \n");
    my_printf("%10x\n", 90);

    // checking with the star*
    printf("Normal printf(): \n");
    printf("%*d\n", 10, 10);

    printf("fake printf(): \n");
    my_printf("%*d\n", 10, 10);

    //width and precision
    printf("Normal printf(): \n");
    printf("Hello World %10.3s\n", "face");

    printf("Fake printf(): \n");
    my_printf("Hello World %10.3s\n", "face");

    // precision
    printf("Normal printf(): \n");
    printf("%.*s\n", 3, "abcdef");

    printf("Fake printf(): \n");
    my_printf("%.*s\n", 3, "abcdef");

    // width with zero flag
    printf("Normal printf(): \n");
    printf("%04d\n", 7);

    printf("Fake printf(): \n");
    my_printf("%04d\n", 7);

    printf("width with zero flag\n");

    printf("Normal printf(): \n");
    printf("%04x\n", 70);

    printf("Fake printf(): \n");
    my_printf("%04x\n", 70);

    // check precision for d
    printf("Normal printf(): \n");
    printf("%.5d\n", 70);

    printf("Fake printf(): \n");
    my_printf("%.5d\n", 70);

    // check precision for d with width also
    printf("Normal printf(): \n");
    printf("%7.5d\n", 70);

    printf("Fake printf(): \n");
    my_printf("%7.5d\n", 70);

    // 0 flag with precision and width
    printf("Normal printf(): \n");
    printf("%07.5d\n", 60);

    printf("Fake printf(): \n");
    my_printf("%07.5d\n", 60);

    // trying precision with x
    printf("Normal printf(): \n");
    printf("%5.3x\n", 70);

    printf("Fake printf(): \n");
    my_printf("%5.3x\n", 70);


    // more flags
    printf("Normal printf(): \n");
    printf("%04X\n",3);

    printf("Fake printf(): \n");
    my_printf("%04X\n",3);

    // deal with flags with width
    printf("Normal printf(): \n");
    printf("%+2d\n", 555);

    printf("Fake printf(): \n");
    my_printf("%+2d\n", 555);

    printf("Normal printf(): \n");
    printf("%6d\n", -400);

    printf("Fake printf(): \n");
    my_printf("%6d\n", -400);

    // testing with the hash flag
    printf("test\n");

    printf("Normal printf(): \n");
    printf("%#5.2x\n", 400);

    printf("Fake printf(): \n");
    my_printf("%#5.2x\n", 400);

    printf("Normal printf(): \n");
    printf("%#5.2X\n", 400);

    printf("Fake printf(): \n");
    my_printf("%#5.2X\n", 400);

    printf("Normal printf(): \n");
    printf("%5.2d\n", 40);

    printf("Fake printf(): \n");
    my_printf("%5.2d\n", 40);

    printf("Normal printf(): \n");
    printf("%02.5d\n", 40);

    printf("Fake printf(): \n");
    my_printf("%02.5d\n", 40);
    
    // negative with hex
    printf("Normal printf(): \n");
    printf("%5.2x\n", -40);

    printf("Fake printf(): \n");
    my_printf("%5.2x\n", -40);

    // plus flag with width bigger than precision
    printf("Normal printf(): \n");
    printf("%6c   hi %+4.2d\n", 'c', 6);

    printf("Fake printf(): \n");
    my_printf("%6c   hi %+4.2d\n", 'c', 6);

    printf("Normal printf(): \n");
    printf("%+04.5d\n", 6);

    printf("Fake printf(): \n");
    my_printf("%+04.5d\n", 6);

    // plus with zeroes
    printf("Normal printf(): \n");
    printf("%+4d\n", 6);

    printf("Fake printf(): \n");
    my_printf("%+4d\n", 6);

    // plus without zeroes
    printf("Normal printf(): \n");
    printf("%+4d\n", 6);

    printf("Fake printf(): \n");
    my_printf("%+4d\n", 6);
    
    // plus sign but negative
    printf("Normal printf(): \n");
    printf("%+4d\n", -6);

    printf("Fake printf(): \n");
    my_printf("%+4d\n", -6);

    // left comparison with precision involved
    printf("Normal printf(): \n");
    printf("|%-10.3d|\n", 42);    // Left-align 42 in a field of width 10

    printf("Fake printf(): \n");
    my_printf("|%-10.3d|\n", 42);

    // left comparison without precision involved
    printf("Normal printf(): \n");
    printf("|%-10d|\n", 42);    // Left-align 42 in a field of width 10

    printf("Fake printf(): \n");
    my_printf("|%-10d|\n", 42);

    // left with c
    printf("Normal printf(): \n");
    printf("|%-10c|\n", 'c');    // Left-align 42 in a field of width 10

    printf("Fake printf(): \n");
    my_printf("|%-10c|\n", 'c');

    // left with s
    printf("Normal printf(): \n");
    printf("|%-10s|\n", "left");    // Left-align 42 in a field of width 10

    printf("Fake printf(): \n");
    my_printf("|%-10s|\n", "left");

    return 0;
}