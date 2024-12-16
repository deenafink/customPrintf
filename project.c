#include <stdio.h>
#include <string.h>
// plan is to use putc() or putchar() to take a char at a time and put them into a list which will ultimately be printed
// loop through the first parameter and get each char into an array
// put them to stdout
// maybe use ascii to help with identifiers?


// next step: if encounter % then go to a section that asks if is %d, %x, %c, or %s and do different things based on that
// if %d then need to add to the array as a decimal

void my_printf(char *phrase, int nums) {
    char preview[100];
    int index = 0;

    // add to the buffer
    while (*phrase != '\0') {
        // if we are up to a %
        if (*phrase == '%') {
            // go to the next character to get the type field
            phrase++;
            if (*phrase == 'd') {
                // type cast to an int in case it was a float or something
                // check what happens in real printf() if a chars are put in or something else
                int temp = nums; // over here would get the real int from the variable
                temp = (int) temp;
                // convert back to a string/chars
                char inString[10];
                int indexS = 0;

                while (temp > 0) {
                    inString[indexS] = temp % 10;
                    printf("inString[indexS]: %d\n", inString[indexS]);
                    temp /= 10; // get the next digit
                    // go to the next spot in the inString
                    indexS++;
                }
                int len = strlen(inString);
                printf("this is len: %d\n", len);
                printf("Array elements: ");
                for (int i = 0; i < len; i++) {
                    printf("hello %d \n", inString[i]); // Print each element
                }

                // now we should have a string of the digits but in backwards so loop backwards and add to preview array
                int *ptr = &phrase; // *ptr now holds the memory address of phrase
                for (int i = len-1; i>=0; i--) {
                    
                    char letter;
                    printf("*ptr = %d\n", *ptr);
                    printf("this is inString[i]: %d\n", inString[i]);
                    letter = inString[i];
                    printf("this is what it is now: %d\n", letter);
                    preview[index] = (char) letter;
                    printf("preview: %d\n", preview[index]);
                    *ptr++;
                    printf("memory location: %d\n", ptr);
                    index++;
                }   
            }
            printf("preview: %d\n", preview[index]);
            phrase++;
            printf("this is what it is afterwards");
        }
        else {
            preview[index] = *phrase;
            phrase++;
            index++;
            }
        
    }

    // terminate the phrase
    

    // putchar them to stout
    printf("over here");
    for (int i=0; i<strlen(preview); i++) {
        putchar(preview[i]);
    }
}

int main()
{
    printf("Normal printf(): ");
    printf("Hello World %d", 82);

    printf("Fake printf(): ");
    my_printf("Hello World %df", 82);

    return 0;
}