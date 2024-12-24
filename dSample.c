if (*phrase == 'd') {
                int num = va_arg(ap, int); // get the next argument
                // cast it into an int
                int ascii = num;
                int negative = 0;
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
                }
                char sign = '0';
                // get the sign
                if (negative) {
                    sign = '-';
                }
                else if (plus_flag) {
                    sign = '+';
                }
                
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

                // for left aligned
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
            }     22