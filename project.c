#include <stdio.h>
//#include <string.h>
#include <stdarg.h>
// plan is to use putc() or putchar() to take a char at a time and put them into a list which will ultimately be printed
// loop through the first parameter and get each char into an array
// put them to stdout
// maybe use ascii to help with identifiers?


// next step: if encounter % then go to a section that asks if is %d, %x, %c, or %s and do different things based on that
// if %d then need to add to the array as a decimal
char get_sign(int negative, int plus_flag) {
    char sign = '0';
    // get the sign
    if (negative) {
        sign = '-';
    }
    else if (plus_flag) {
        sign = '+';
    }
    return sign;
}

void store_numbers(int num, int *index, char * str) {
    if (num == 0)
        str[(*index)++] = '0';
    else 
        while (num > 0) {
            int temp = num % 10;
            // add this digit to the string
            str[*index] = '0' + temp;
            (*index)++;
            // get rid of last digit
            num /= 10;
        }
    str[*index] = '\0'; 
}

void print_d(int num, int plus_flag, int left_alignment, int zeroes, int width, int precision) {
    int ascii = num;
    int negative = 0;
    // sizes can only be 10 places anyway
    char str[12]; // later want to turn the int into a str to print each digit individually
    int index = 0;

    // edge case of 0
    // if (ascii == 0) {
    //     str[index] = '0';
    //     index++;
    // }

    // if negative number
    if (ascii < 0) {
        negative = 1; // set negative to 1
        ascii *= -1; // to turn the rest of the number positive
    }
    
    // turn the into a string, but backwards
    // can be a function here
    // while (ascii > 0) {
    //     int temp = ascii % 10;
    //     // add this digit to the string
    //     str[index] = '0' + temp;
    //     index++;
    //     // get rid of last digit
    //     ascii /= 10;
    // }
    store_numbers(ascii, &index, str);
    char sign = get_sign(negative, plus_flag);
    
    int totalWidth = index;

    // get the number of zeroes needed for precision
    int addedZeroes = 0;

    // get the total number of chars needed for width after the added precision ones
    if (index < precision) {
        addedZeroes = precision-index;
        
    }
    totalWidth += addedZeroes;
    if (sign != '0') {
        totalWidth++; // add one more width after the sign
    }

    int widthSpaces = width - totalWidth;

    // for left aligned: order is sign, precision, digits, width
    if (left_alignment == 1) {
        //if theres a sign, add it
        if (sign != '0') putchar(sign);
        //if theres precision, add it
        for (int i=0; i<addedZeroes; i++) {
            putchar('0');
        }
        // add the digits
        for (int i = index-1; i >= 0; i--) {
            putchar(str[i]);
        }
        // add the width in spaces
        for (int i=0; i<widthSpaces; i++)
            putchar(' ');
    }
    // for regular
    else {
        // if zeroes is on and totalWidth is greater than width
        // order is sign, width zeroes, precision, digits
        if (zeroes == 1 && widthSpaces > 0) {
            // add the sign
            if (sign != '0')
                putchar(sign);
            // add the rest of the zeroes for width
            for (int i=0; i<widthSpaces; i++)
                putchar('0');
            // add the precision zeroes
            for (int i=0; i<addedZeroes; i++)
                putchar('0');
            // add the digits
            for (int i = index-1; i >= 0; i--) 
                putchar(str[i]);
        }
        // if zeroes is off
        // order is width spaces, sign, precision, digits
        else {
            // add the blanks for wide
            for (int i=0; i<widthSpaces; i++)
                putchar(' ');
            // add the sign
            if (sign != '0')
                putchar(sign);
            // add the precision zeroes
            for (int i=0; i<addedZeroes; i++)
                putchar('0');
            // add the digits
            for (int i = index-1; i >= 0; i--) 
                putchar(str[i]);
        }
    }
}

void print_c(char character, int plus_flag, int left_alignment, int zeroes, int width, int precision) {
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

void print_s(char *string, int plus_flag, int left_alignment, int zeroes, int width, int precision) {
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

void print_x(unsigned int num, int plus_flag, int left_alignment, int zeroes, int width, int precision, int hash_flag, char format) {
    // sizes can only be 10 places anyway
    char str[12]; // later want to turn the int into a str to print each digit individually
    int index = 0;

    // edge case of 0
    if (num == 0) {
        str[index] = '0';
        index++;
    }

    // have a list of the hex digits
    char hex[16] = "0123456789abcdef";
    // turn the into a string, but backwards
    while (num > 0) {
        int temp = num % 16;
        // add this digit to the string
        str[index] = hex[temp];
        index++;
        // get rid of last digit
        num /= 16;
    }

    // total number of chars involved
    int totalWidth = index;
        // check if # flag is set
    if (hash_flag == 1) {
        str[index] = format;
        index++;
        str[index] = '0';
        index++;   
        totalWidth += 2;      
    }
    int addedZeroes = 0;
    // get the number of zeroes involved for precision
    if (index < precision) {
        addedZeroes = precision-index;
    }
    totalWidth += addedZeroes;
    // get the number of spaces we need to add for width after precision
    int widthSpaces = width - totalWidth;

    // for left aligned
    if (left_alignment == 1) {
        // add the precision
        for (int i=0; i<(addedZeroes); i++) {
            putchar('0');
        }
        // add the digits
        for (int i = index-1; i >= 0; i--) {
            putchar(str[i]);
        }
        // now add the spaces for width
        for (int i = 0; i <widthSpaces; i--) {
            putchar(str[i]);
        }
    }
    

    // over here need to check how many less than width and then put blank spaces
    else {
        // if zeroes is on and totalWidth is greater than width
        if (zeroes == 1 && widthSpaces > 0) {
            // add the rest of the zeroes for width
            for (int i=0; i<widthSpaces; i++)
                putchar('0');
            // add the precision zeroes
            for (int i=0; i<addedZeroes; i++)
                putchar('0');
            // add the digits
            for (int i = index-1; i >= 0; i--) 
                putchar(str[i]);
        }
        // if zeroes is off
        else {
            // add the blanks for wide
            for (int i=0; i<widthSpaces; i++)
                putchar(' ');
            // add the precision zeroes
            for (int i=0; i<addedZeroes; i++)
                putchar('0');
            // add the digits
            for (int i = index-1; i >= 0; i--) 
                putchar(str[i]);
        }
    }
}

void print_m(char *string, int plus_flag, int left_alignment, int zeroes, int width, int precision) {
    //printf("%d\n", 2+3)
    // while it's a number, get the number
    int num1 = 0;
    int num2 = 0;
    char addOrMinus = '\0';
    char str[12];

    while (*string >= '0' && *string <= '9') {
        // get the int 
        num1 = (num1 * 10) + *string - '0';
        string++;
    }
    // get the sign
    if (*string == '+')
        addOrMinus = '+';
    else if (*string == '-')
        addOrMinus = '-';
    else if (*string == '*')
        addOrMinus = '*';
    string++;

    // while its a number
    while (*string >= '0' && *string <= '9') {
        // get the int 
        num2 = (num2 * 10) + *string - '0';
        string++;
    }
    int ret = 0;
    // do the math and store the answer in ret
    if (addOrMinus == '+')
        ret = num1+num2;
    else if (addOrMinus == '-')
        ret = num1-num2;
    else if (addOrMinus == '*')
        ret = num1 * num2;
    
    int index = 0;
    store_numbers(ret, &index, str);

    for (int i = index-1; i >= 0; i--) 
        putchar(str[i]);
    // now need to print out the numbers one by one
}

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
                print_d(num, plus_flag, left_alignment, zeroes, width, precision);
            }     
            // prints it as a char
            if (*phrase == 'c') {
                char character = va_arg(ap, int); // get the next argument, the parameter is an int idk why can ask that
                print_c(character, plus_flag, left_alignment, zeroes, width, precision);
            }
            // s should be the same thing just multiple character so will move through it and print one by one
            if (*phrase == 's') {
                char *string = va_arg(ap, char*); // get the next argument
                print_s(string, plus_flag, left_alignment, zeroes, width, precision);
            } 
                
            // if x: unsigned int as a hexadecimal number. x uses lower-case letters and X uses upper-case. could be similar to d
            // use 16 instead of 10
            // right now not working fully
            if (*phrase == 'x' || *phrase == 'X') {
                unsigned int num = va_arg(ap, int); // get the next argument, the parameter is an int idk why can ask that
                print_x(num, plus_flag, left_alignment, zeroes, width, precision, hash_flag, *phrase);
            }
            if (*phrase == 'm') {
                char *string = va_arg(ap, char*); // get the next argument
                print_m(string, plus_flag, left_alignment, zeroes, width, precision);
            } 
        }
        else {
            putchar(*phrase);
        }
        phrase++;
    }
    va_end(ap); // cleanup the va_list
}

// int main() {
//     printf("Normal printf(): ");
//     printf("Hello World %d\n", 10001);

//     printf("Fake printf(): ");
//     my_printf("Hello World %d\n", 10001);

//     printf("Normal printf(): ");
//     printf("Hello World %d what is your age %d\n", 'f', 3);

//     printf("Fake printf(): ");
//     my_printf("Hello World %d what is your age %d\n", 'f', 3);

//     printf("Normal printf(): ");
//     printf("Hello World %d\n", 0);

//     printf("Fake printf(): ");
//     my_printf("Hello World %d\n", 0);

//     printf("Normal printf(): ");
//     printf("Hello World %d\n", -55);

//     printf("Fake printf(): ");
//     my_printf("Hello World %d\n", -55);

//     printf("Normal printf(): ");
//     printf("Hello World %+d\n", 55);

//     printf("Fake printf(): ");
//     my_printf("Hello World %+d\n", 55);

//     // c
//     printf("Normal printf(): ");
//     printf("Hello World %c\n", 'c');

//     printf("Fake printf(): ");
//     my_printf("Hello World %c\n", 'c');

//     // s
//     printf("Normal printf(): ");
//     printf("Hello World %s\n", "string");

//     printf("Fake printf(): ");
//     my_printf("Hello World %s\n", "string");

//     // trying all of them together
//     printf("Normal printf(): ");
//     printf("This is a: %s, This is a number: %d, This is a char: %c\n", "string", 4, 'c');

//     printf("Fake printf(): ");
//     my_printf("This is a: %s, This is a number: %d, This is a char: %c\n", "string", 4, 'c');

//     // x
//     printf("Normal printf(): ");
//     printf("Hello World %x\n", 26);

//     printf("Fake printf(): ");
//     my_printf("Hello World %x\n", 26);

//     printf("Normal printf(): ");
//     printf("Hello World %x\n", 689);

//     printf("Fake printf(): ");
//     my_printf("Hello World %x\n", 689);

//     printf("Normal printf(): \n");
//     printf("Hello World %10d whats up\n", 689);

//     printf("Fake printf(): \n");
//     my_printf("Hello World %10d whats up\n", 689);

//     printf("Normal printf(): \n");
//     printf("Hello World %d\n", 689);

//     printf("Fake printf(): \n");
//     my_printf("Hello World %d\n", 689);

//     printf("Normal printf(): \n");
//     printf("Hello World %10c\n", 'f');

//     printf("Fake printf(): \n");
//     my_printf("Hello World %10c\n", 'f');

//     printf("Normal printf(): \n");
//     printf("Hello World %10s\n", "face");

//     printf("Fake printf(): \n");
//     my_printf("Hello World %10s\n", "face");

//     // // width with x
//     printf("Normal printf(): \n");
//     printf("%10x\n", 90);

//     printf("fake printf(): \n");
//     my_printf("%10x\n", 90);

//     ////checking with the star*
//     printf("Normal printf(): \n");
//     printf("%*d\n", 10, 10);

//     printf("fake printf(): \n");
//     my_printf("%*d\n", 10, 10);

//     //width and precision
//     printf("Normal printf(): \n");
//     printf("Hello World %10.3s\n", "face");

//     printf("Fake printf(): \n");
//     my_printf("Hello World %10.3s\n", "face");

//     // precision
//     printf("Normal printf(): \n");
//     printf("%.*s\n", 3, "abcdef");

//     printf("Fake printf(): \n");
//     my_printf("%.*s\n", 3, "abcdef");

//     // width with zero flag
//     printf("Normal printf(): \n");
//     printf("%04d\n", 7);

//     printf("Fake printf(): \n");
//     my_printf("%04d\n", 7);

//     printf("width with zero flag\n");

//     printf("Normal printf(): \n");
//     printf("%04x\n", 70);

//     printf("Fake printf(): \n");
//     my_printf("%04x\n", 70);

//     // check precision for d
//     printf("Normal printf(): \n");
//     printf("%.5d\n", 70);

//     printf("Fake printf(): \n");
//     my_printf("%.5d\n", 70);

//     // check precision for d with width also
//     printf("Normal printf(): \n");
//     printf("%7.5d\n", 70);

//     printf("Fake printf(): \n");
//     my_printf("%7.5d\n", 70);

//     // trying precision with x
//     printf("Normal printf(): \n");
//     printf("%5.3x\n", 70);

//     printf("Fake printf(): \n");
//     my_printf("%5.3x\n", 70);


//     // more flags
//     printf("Normal printf(): \n");
//     printf("%04X\n",3);

//     printf("Fake printf(): \n");
//     my_printf("%04X\n",3);

//     // deal with flags with width
//     printf("Normal printf(): \n");
//     printf("%+2d\n", 555);

//     printf("Fake printf(): \n");
//     my_printf("%+2d\n", 555);

//     printf("Normal printf(): \n");
//     printf("%6d\n", -400);

//     printf("Fake printf(): \n");
//     my_printf("%6d\n", -400);

//     // testing with the hash flag
//     printf("test\n");

//     printf("Normal printf(): \n");
//     printf("%#5.2x\n", 400);

//     printf("Fake printf(): \n");
//     my_printf("%#5.2x\n", 400);

//     printf("Normal printf(): \n");
//     printf("%#5.2X\n", 400);

//     printf("Fake printf(): \n");
//     my_printf("%#5.2X\n", 400);

//     printf("Normal printf(): \n");
//     printf("%5.2d\n", 40);

//     printf("Fake printf(): \n");
//     my_printf("%5.2d\n", 40);
    
//     // negative with hex
//     printf("Normal printf(): \n");
//     printf("%5.2x\n", -40);

//     printf("Fake printf(): \n");
//     my_printf("%5.2x\n", -40);

//     // plus flag with width bigger than precision
//     printf("Normal printf(): \n");
//     printf("%6c   hi %+4.2d\n", 'c', 6);

//     printf("Fake printf(): \n");
//     my_printf("%6c   hi %+4.2d\n", 'c', 6);

//     // plus with zeroes
//     printf("Normal printf(): \n");
//     printf("%+4d\n", 6);

//     printf("Fake printf(): \n");
//     my_printf("%+4d\n", 6);

//     // plus without zeroes
//     printf("Normal printf(): \n");
//     printf("%+4d\n", 6);

//     printf("Fake printf(): \n");
//     my_printf("%+4d\n", 6);
    
//     // plus sign but negative
//     printf("Normal printf(): \n");
//     printf("%+4d\n", -6);

//     printf("Fake printf(): \n");
//     my_printf("%+4d\n", -6);

//     // left comparison with precision involved
//     printf("Normal printf(): \n");
//     printf("|%-10.3d|\n", 42);    

//     printf("Fake printf(): \n");
//     my_printf("|%-10.3d|\n", 42);

//     // left comparison without precision involved
//     printf("Normal printf(): \n");
//     printf("|%-10d|\n", 42);    

//     printf("Fake printf(): \n");
//     my_printf("|%-10d|\n", 42);

//     // left with c
//     printf("Normal printf(): \n");
//     printf("|%-10c|\n", 'c');    

//     printf("Fake printf(): \n");
//     my_printf("|%-10c|\n", 'c');

//     //left with s
//     printf("Normal printf(): \n");
//     printf("%-10s\n", "left");    

//     printf("Fake printf(): \n");
//     my_printf("%-10s\n", "left");

//     // left with s
//     printf("Normal printf(): \n");
//     printf("%10s\n", "right");    

//     printf("Fake printf(): \n");
//     my_printf("%10s\n", "right");

//     printf("Normal printf(): \n");
//     printf("%d\n", 5);    

//     printf("Fake printf(): \n");
//     my_printf("%d\n", 5);

//     printf("Normal printf(): \n");
//     printf("%c\n", 'c');    

//     printf("Fake printf(): \n");
//     my_printf("%c\n", 'c');

//     printf("Normal printf(): \n");
//     printf("%d\n", 5);    

//     printf("Fake printf(): \n");
//     my_printf("%d\n", 5);

//     printf("Normal printf(): \n");
//     printf("%s\n", "choja");    

//     printf("Fake printf(): \n");
//     my_printf("%s\n", "choja");

//     printf("Normal printf(): \n");
//     printf("%x\n", 2454);    

//     printf("Fake printf(): \n");
//     my_printf("%x\n", 2454);

//     printf("Fake printf(): \n");
//     my_printf("%m\n", "5+2");

//     printf("Fake printf(): \n");
//     my_printf("%m\n", "5-2");

//     printf("Fake printf(): \n");
//     my_printf("%m\n", "5*2");


//     return 0;
// }