#include <stdio.h>
#include <stdarg.h>


// function to get the sign; either plus, minus, or nothing
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
// function to handle division by 0
void handle_error() {
    char *message = "Error: Division by zero";
    while (*message) {
        putchar(*message);
        message++;
    }
}

// function to store numbers in a list to later print one by one
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

// function for %d
void print_d(int num, int plus_flag, int left_alignment, int zeros, int width, int precision, int space_flag) {
    int negative = 0;
    // sizes can only be 10 places anyway
    char str[12]; // later want to turn the int into a str to print each digit individually
    int index = 0;

    // if negative number
    if (num < 0) {
        negative = 1; // set negative to 1
        num *= -1; // to turn the rest of the number positive
    }

    // store the numbers in a str array
    store_numbers(num, &index, str);
    // get if supposed to print a + or -
    char sign = get_sign(negative, plus_flag);
    
    int totalWidth = index;

    // get the number of zeros needed for precision
    int addedPrecision = 0;

    // get the total number of chars needed for width after the added precision ones
    if (index < precision) {
        addedPrecision = precision-index;
    }
    
    totalWidth += addedPrecision;
    if (sign != '0') {
        totalWidth++; // add one more width after the sign
    }

    //if blank space flag is on and sign == '0', make width spaces one less for this one
    if (space_flag == 1 && sign == '0')
        totalWidth++;

    int widthSpaces = width - totalWidth;

    // for left aligned: order is sign, precision, digits, width
    if (left_alignment == 1) {
        //if theres a sign, add it
        if (sign != '0') putchar(sign);
        // if blank space flag is on and sign == '0', put a space
        if (space_flag == 1 && sign == '0')
            putchar(' ');
        //if theres precision, add it
        for (int i=0; i<addedPrecision; i++) {
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
        // if zeros is on and totalWidth is greater than width
        // order is sign, width zeros, precision, digits
        if (zeros == 1 && widthSpaces > 0) {
            // add the sign
            if (sign != '0')
                putchar(sign);
            // if blank space flag is on and sign == '0', put a space
            if (space_flag == 1 && sign == '0')
                putchar(' ');
            // add the rest of the zeros for width
            for (int i=0; i<widthSpaces; i++)
                putchar('0');
            // add the precision zeros
            for (int i=0; i<addedPrecision; i++)
                putchar('0');
            // add the digits
            for (int i = index-1; i >= 0; i--) 
                putchar(str[i]);
        }
        // if zeros is off
        // order is width spaces, sign, precision, digits
        else {
            // add the blanks for wide
            for (int i=0; i<widthSpaces; i++)
                putchar(' ');
            // add the sign
            if (sign != '0')
                putchar(sign);
            // if blank space flag is on and sign == '0', put a space
            if (space_flag == 1 && sign == '0')
                putchar(' ');
            // add the precision zeros
            for (int i=0; i<addedPrecision; i++)
                putchar('0');
            // add the digits
            for (int i = index-1; i >= 0; i--) 
                putchar(str[i]);
        }
    }
}
// %c
void print_c(char character, int left_alignment, int width) {
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
// %s
void print_s(char *string, int left_alignment, int width, int precision) {
    // save the first spot in the string
    char *copy = string;

    // get length of the string
    int len = 0;
    while (*string != '\0') {
        len++;
        string++;
    }

    //restore the pointer back to the first char
    string = copy;

    // if normal alignment
    if (left_alignment == 0) {
        // precision
        if (precision > 0) {
            // width and precision together
            if (width > precision) {
                // add diff number of spaces for the width
                int diff = width-precision;
                for (int i=0; i<diff; i++)
                    putchar(' ');
            }
        
            int num = 0; // adding chars, but not more than precision
            while (*string != '\0' && num < precision) {
                putchar(*string);
                string++;
                num++;
            }
        }

        // insert the spaces for width (without precision specified)
        else {
            // if the width is wider than the length of str
            if (width > len) {
                // add diff many zeros to meet width
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
    // if left alignment, same steps but chars first
    else {
        // with precision
        if (precision > 0) {
            int num = 0; // adding chars, but not more than precision
            while (*string != '\0' && num < precision) {
                putchar(*string);
                string++;
                num++;
            }
            // add diff many spaces for width
            if (width > precision) {
                int diff = width-precision;
                for (int i=0; i<diff; i++)
                    putchar(' ');
            }
        }

        // if no precision just add the spaces for width
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

void print_x(unsigned int num, int plus_flag, int left_alignment, int zeros, int width, int precision, int hash_flag, char format) {
    char str[12]; // later want to turn the int into a str to print each digit individually
    int index = 0;

    // edge case of 0
    if (num == 0) {
        str[index] = '0';
        index++;
    }

    // have a list of the hex digits
    char hex[16] = "0123456789abcdef";
    
    // not using the function because of the hex conversion // store backwards in list
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
        // format is going to be either X or x
        str[index] = format;
        index++;
        str[index] = '0';
        index++;   
        totalWidth += 2;      
    }

    int addedPrecision = 0;
    // get the number of zeros involved for precision
    if (index < precision) {
        addedPrecision = precision-index;
    }
    
    totalWidth += addedPrecision;
    // get the number of spaces we need to add for width after precision
    int widthSpaces = width - totalWidth;

    // for left aligned
    if (left_alignment == 1) {
        // add the precision
        for (int i=0; i<(addedPrecision); i++) {
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
        // if zeros is on and totalWidth is greater than width
        if (zeros == 1 && widthSpaces > 0) {
            // add the rest of the zeros for width
            for (int i=0; i<widthSpaces; i++)
                putchar('0');
            // add the precision zeros
            for (int i=0; i<addedPrecision; i++)
                putchar('0');
            // add the digits
            for (int i = index-1; i >= 0; i--) 
                putchar(str[i]);
        }
        // if zeros is off
        else {
            // add the blanks for wide
            for (int i=0; i<widthSpaces; i++)
                putchar(' ');
            // add the precision zeros
            for (int i=0; i<addedPrecision; i++)
                putchar('0');
            // add the digits
            for (int i = index-1; i >= 0; i--) 
                putchar(str[i]);
        }
    }
}
// custom %m type which treats the argument as a math expression
// sample format: printf("%d\n", 2+3)
// does int division
void print_m(char *string) {

    int num1 = 0;
    int num2 = 0;
    char operator = '\0';
    char str[12];

    // while it's a number, get it and it and add it to num1
    while (*string >= '0' && *string <= '9') {
        num1 = (num1 * 10) + *string - '0';
        string++;
    }
    // get the sign
    if (*string == '+')
        operator = '+';
    else if (*string == '-')
        operator = '-';
    else if (*string == '*')
        operator = '*';
    else if (*string == '/')
        operator = '/';
    string++;

    // while it's a number, get it and it and add it to num2
    while (*string >= '0' && *string <= '9') {
        // get the int 
        num2 = (num2 * 10) + *string - '0';
        string++;
    }

    // division by 0;
    if (num2 == 0) {
        handle_error();
        return;
    }

    int ret = 0; 
    // do the math with right operation and store the answer in ret
    if (operator == '+')
        ret = num1+num2;
    else if (operator == '-')
        ret = num1-num2;
    else if (operator == '*')
        ret = num1 * num2;
    else if (operator == '/')
        ret = num1 / num2;
    
    int index = 0;
    // store numbers in a str array
    store_numbers(ret, &index, str);

    // now need to print out the numbers one by one in reverse stored order
    for (int i = index-1; i >= 0; i--) 
        putchar(str[i]);
}
// custom %b which converts the int into a binary number, including 2's complement
void print_b(int num) {
    // max is 32 bit
    char str[32];
    int index = 0;
    
    // get the positive of the number
    int pos;
    if (num >= 0) {
        pos = num;
    }
    else if (num < 0) {
        pos = -num;
    }
    
    // get the number in binary stored backwards in an array
    while (pos > 0) {
        int temp = pos % 2;
        // add this digit to the string
        str[index] = '0' + temp;
        index++;
        // get rid of last digit
        pos /= 2;
    }
    // fill the rest with 0s
    for (int i=index; i<32; i++) {
        str[i] = '0';
    }

    // if num is negative, need two's complement
    if (num < 0) {
        // flip the bits
        for (int i=0; i<32; i++) {
            // 1 if 0, 0 if 1
            str[i] = (str[i] == '0') ? '1':'0';
        }
        // add one with carry on
        int carryOver = 1;
        // adding one to either end works, tried both
        for (int i = 0; i <= 31; i++) {
            // if there is a 0 there, add 1
            if (str[i] == '0' && carryOver == 1) {
                str[i] = '1';
                carryOver = 0;
                break; // rest of array remains the same
            }
            // if theres a one there, carry it over
            if (str[i] == '1' && carryOver == 1){
                str[i] = '0';
            }
        }
    }
    // put the chars one by one backwards
    for (int i = 31; i >= 0; i--) 
        putchar(str[i]);
}
// added a length type, which returns the length of the string becuase c doesn't have a built in function to do that like python's len() wihtout importing a library
void print_l(char *string) {
    char str[12]; // later want to turn the int into a str to print each digit individually
    int index = 0;
    int len = 0;
    // get the length of the string
    while (*string != '\0') {
        len++;
        string++;
    }
    store_numbers(len, &index, str);
    // now print it backwards
    for (int i = index-1; i >= 0; i--)
        putchar(str[i]);
}

// format: %[flags][width][.precision]type
void my_printf(char *phrase, ...) {
    va_list ap; // initialize list for variables
    va_start(ap, phrase); // intialize variable from first parameter
    while (*phrase != '\0') {
        if (*phrase == '%') {
            phrase++; // to get the flag or modifier or type...
            // flags are -, +, , 0, #
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
            int zeros = 0;
            // check if 0 and then do zeros instead of spaces
            if (*phrase == '0') {
                zeros = 1;
                phrase++;
            }

            // hash flag
            int hash_flag = 0;
            if (*phrase == '#') {
                hash_flag = 1;
                phrase++;
            }

            // space flag
            int space_flag = 0;
            if (*phrase == ' ') {
                space_flag = 1;
                phrase++;
            }

            // width field the number is the minimum number of chars in output
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

            // prints as an int
            if (*phrase == 'd') {
                int num = va_arg(ap, int); // get the next argument
                print_d(num, plus_flag, left_alignment,  zeros, width, precision, space_flag);
            }     
            // prints it as a char
            if (*phrase == 'c') {
                char character = va_arg(ap, int); // get the next argument
                print_c(character, left_alignment, width);
            }
            // prints a string
            if (*phrase == 's') {
                char *string = va_arg(ap, char*); // get the next argument
                print_s(string, left_alignment, width, precision);
            } 
                
            // unsigned int as a hexadecimal number. x uses lower-case letters and X uses upper-case.
            if (*phrase == 'x' || *phrase == 'X') {
                unsigned int num = va_arg(ap, int); // get the next argument, the parameter is an int idk why can ask that
                print_x(num, plus_flag, left_alignment, zeros, width, precision, hash_flag, *phrase);
            }
            // does simple math problem
            if (*phrase == 'm') {
                char *string = va_arg(ap, char*); // get the next argument
                print_m(string);
            } 
            // converts int to binary number
            if (*phrase == 'b') {
                int num = va_arg(ap, int); // get the next argument
                print_b(num);
            }
            // gets length of string
            if (*phrase == 'l') {
                char *string = va_arg(ap, char*); // get the next argument
                print_l(string);
            } 
        }
        else {
            putchar(*phrase);
        }
        phrase++;
    }
    va_end(ap); // cleanup the va_list
}