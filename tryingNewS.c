// if (*phrase == 's') {
//                 char *string = va_arg(ap, char*); // get the next argument
//                 char *copy = string;

//                 // get length of the string
//                 int len = 0;
//                 while (*string != '\0') {
//                     len++;
//                     string++;
//                 }
//                 //restore the pointer to the original point in memory
//                 string = copy;
                
//                 int totalWidth = len;
//                 int addedZeroes = 0;
//                 if (len < precision) {
//                     addedZeroes = precision-len;
//                     totalWidth += addedZeroes;
//                 }
//                 else {
//                     totalWidth -= (precision-len);
//                 }
//                 int widthSpaces = width-totalWidth;
                
//                 // if normal alignment
//                 // deal with precision
//                 if (left_alignment == 0) {
//                     // precision spaces
//                     for (int i=0; i<addedZeroes; i++)
//                         putchar(' ');
//                     // now width spaces
//                     for (int i=0; i<widthSpaces; i++)
//                         putchar(' ');
//                      // this is for precision to not go over
//                     int num = 0;
//                     if (precision > 0) {
//                         while (*string != '\0' && num < precision) {
//                         putchar(*string);
//                         string++;
//                         num++;
//                         }
//                     }  
//                     else {
//                         while (*string != '\0') {
//                         putchar(*string);
//                         string++;
//                         num++;
//                         }
//                     }
//                 }
//                 // left alignment
//                 else {
//                      // this is for precision to not go over
//                     int num = 0;
//                     if (precision > 0) {
//                         while (*string != '\0' && num < precision) {
//                         putchar(*string);
//                         string++;
//                         num++;
//                         }
//                     }  
//                     else {
//                         while (*string != '\0') {
//                         putchar(*string);
//                         string++;
//                         num++;
//                         }
//                     }
//                     // precision spaces
//                     for (int i=0; i<addedZeroes; i++)
//                         putchar(' ');
//                     // now width spaces
//                     for (int i=0; i<widthSpaces; i++)
//                         putchar(' ');
//                 }
                    
            
//             } 