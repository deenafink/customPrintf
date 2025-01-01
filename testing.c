#include <stdio.h>

void my_printf(const char *format, ...);

int main() {
    // d
    printf("These tests show real printf and then my_printf version below\n");
    printf("D TESTING:\n");
    printf("\n");
    // text with numbers
    printf("text with numbers:\n");
    printf("Normal printf(): ");
    printf("Hello World %d\n", 10001);

    printf("Fake printf(): ");
    my_printf("Hello World %d\n", 10001);

    printf("\n");
    // text with numbers and chars as parameters
    printf("with numbers and chars\n");
    printf("text with numbers and chars:\n");
    printf("Normal printf(): ");
    printf("Hello World %d what is your age %d\n", 'f', 3);

    printf("Fake printf(): ");
    my_printf("Hello World %d what is your age %d\n", 'f', 3);

    printf("\n");
    // %d with 0
    printf("with 0 edgecase:\n");
    printf("Normal printf(): ");
    printf("Hello World %d\n", 0);

    printf("Fake printf(): ");
    my_printf("Hello World %d\n", 0);

    printf("\n");
    // %d with negative number
    printf("negative number:\n");
    printf("Normal printf(): ");
    printf("Hello World %d\n", -55);

    printf("Fake printf(): ");
    my_printf("Hello World %d\n", -55);

    printf("\n");
    // %d with positive flag
    printf("+ flag:\n");
    printf("Normal printf(): ");
    printf("Hello World %+d\n", 55);

    printf("Fake printf(): ");
    my_printf("Hello World %+d\n", 55);

    printf("\n");
    // using precision flag with %d // should add four zeroes
    printf("precision:\n");
    printf("Normal printf(): \n");
    printf("%.5d\n", 70);

    printf("Fake printf(): \n");
    my_printf("%.5d\n", 70);

    printf("\n");
    // check precision for d with width also, width is wider than precision
    printf("precision with width (width is larger than precision)\n");
    printf("Normal printf(): \n");
    printf("%7.5d\n", 70);

    printf("Fake printf(): \n");
    my_printf("%7.5d\n", 70);

    printf("Normal printf(): \n");
    printf("%5.2d\n", 40);

    printf("Fake printf(): \n");
    my_printf("%5.2d\n", 40);

    printf("\n");
    // precision is larger than width
    printf("precision is larger than width:\n");
    printf("Normal printf(): \n");
    printf("%2.6d\n", 84);

    printf("Fake printf(): \n");
    my_printf("%2.6d\n", 84);

    printf("\n");
    // plus flag with negative number
    printf("plus flag with negative number (don't print it)\n");
    printf("Normal printf(): \n");
    printf("%+d\n", -555);

    printf("Fake printf(): \n");
    my_printf("%+d\n", -555);

    printf("\n");
     // testing flags working with width
    printf("flags and width becayse they need to be included if addingn extra chars:\n");
    printf("Normal printf(): \n");
    printf("%+2d\n", 555);

    printf("Fake printf(): \n");
    my_printf("%+2d\n", 555);

    printf("\n");
    // negative number with width
    printf("negartive number with width:\n");
    printf("Normal printf(): \n");
    printf("%6d\n", -400);

    printf("Fake printf(): \n");
    my_printf("%6d\n", -400);

    printf("\n");
    // plus flag with width
    printf("plus flag with width:\n");
    printf("Normal printf(): \n");
    printf("%+4d\n", 6);

    printf("Fake printf(): \n");
    my_printf("%+4d\n", 6);

    printf("\n");
    // plus sign but negative with width
    printf("Plus sign, negative number, with width:\n");
    printf("Normal printf(): \n");
    printf("%+4d\n", -6);

    printf("Fake printf(): \n");
    my_printf("%+4d\n", -6);

    printf("\n");
    // left alignment flag with precision involved
    printf("left alignment, precision too:\n");
    printf("Normal printf(): \n");
    printf("|%-10.3d|\n", 42);    

    printf("Fake printf(): \n");
    my_printf("|%-10.3d|\n", 42);

    printf("\n");
    // left alignment without precision involved
    printf("left alignment, no precision:\n");
    printf("Normal printf(): \n");
    printf("|%-10d|\n", 42);    

    printf("Fake printf(): \n");
    my_printf("|%-10d|\n", 42);

    printf("\n");
    // width with zero flag
    printf("width with zero flag:\n");
    printf("Normal printf(): \n");
    printf("%04d\n", 7);

    printf("Fake printf(): \n");
    my_printf("%04d\n", 7);

    printf("\n");
    // with text embedded
    printf("with text embedded:\n");
    printf("Normal printf(): \n");
    printf("Hello World %10d whats up\n", 689);

    printf("Fake printf(): \n");
    my_printf("Hello World %10d whats up\n", 689);

    printf("\n");
    //checking with the star*
    printf("with the *:\n");
    printf("Normal printf(): \n");
    printf("%*d\n", 10, 10);

    printf("fake printf(): \n");
    my_printf("%*d\n", 10, 10);

    printf("\n");
    // checking the space flag
    printf("space flag:\n");
    printf("Normal printf(): \n");
    printf("% d\n", 787);

    printf("fake printf(): \n");
    my_printf("% d\n", 787);

    // space flag with width
    printf("Normal printf(): \n");
    printf("|% 5d|\n", 7);

    printf("fake printf(): \n");
    my_printf("|% 5d|\n", 7);
    
    // with precision
    printf("Normal printf(): \n");
    printf("|% 3.7d|\n", 80);

    printf("fake printf(): \n");
    my_printf("|% 3.7d|\n", 80);

    // space with zero flag and width
    printf("space with zero flag and width");
    printf("Normal printf(): \n");
    printf("|%0 7d|\n", 56);

    printf("fake printf(): \n");
    my_printf("|%0 7d|\n", 56);

    // space with left alignment
    printf("space with left alignment");
    printf("Normal printf(): \n");
    printf("|%-4d|\n", 200);

    printf("fake printf(): \n");
    my_printf("|%-4d|\n", 200);

    // %c testing
    printf("\n");
    printf("\n");
    printf("C TESTING:\n");
    printf("\n");

    printf("Normal printf(): ");
    printf("Hello World %c\n", 'c');

    printf("Fake printf(): ");
    my_printf("Hello World %c\n", 'c');

    printf("\n");
    // c testing with width
    printf("c testing with width:\n");
    printf("Normal printf(): \n");
    printf("Hello World %10c\n", 'f');

    printf("Fake printf(): \n");
    my_printf("Hello World %10c\n", 'f');

    printf("\n");
    // left alignment with c
    printf("left alignment:\n");
    printf("Normal printf(): \n");
    printf("|%-10c|\n", 'c');    

    printf("Fake printf(): \n");
    my_printf("|%-10c|\n", 'c');

    // s
    printf("\n");
    printf("\n");
    printf("S TESTING:\n");

    printf("\n");
    printf("Normal printf(): \n");
    printf("%s\n", "hello");    

    printf("Fake printf(): \n");
    my_printf("%s\n", "hello");

    printf("Normal printf(): ");
    printf("Hello World %s\n", "string");

    printf("Fake printf(): ");
    my_printf("Hello World %s\n", "string");

    printf("\n");
    // width with s
    printf("with width:\n");
    printf("Normal printf(): \n");
    printf("Hello World %9s\n", "face");

    printf("Fake printf(): \n");
    my_printf("Hello World %9s\n", "face");

    printf("Normal printf(): \n");
    printf("%10s\n", "right");    

    printf("Fake printf(): \n");
    my_printf("%10s\n", "right");

    printf("\n");
    //left with s
    printf("left alignment:\n");
    printf("Normal printf(): \n");
    printf("%-10s\n", "left");    

    printf("Fake printf(): \n");
    my_printf("%-10s\n", "left");

    printf("\n");
    // precision
    printf("with precision:\n");
    printf("Normal printf(): \n");
    printf("%.*s\n", 3, "abcdef");

    printf("Fake printf(): \n");
    my_printf("%.*s\n", 3, "abcdef");

    // %x testing
    printf("\n");
    printf("\n");
    printf("X TESTING:\n");
    printf("\n");

    printf("2455 in hex\n");
    printf("Normal printf(): \n");
    printf("%x\n", 2454);    

    printf("Fake printf(): \n");
    my_printf("%x\n", 2454);

    printf("\n");
    printf("26 in hex\n");
    printf("Normal printf(): ");
    printf("Hello World %x\n", 26);

    printf("Fake printf(): ");
    my_printf("Hello World %x\n", 26);

    printf("\n");
    printf("689 in hex\n");
    printf("Normal printf(): ");
    printf("%x\n", 689);

    printf("Fake printf(): ");
    my_printf("%x\n", 689);

    printf("\n");
    printf("0 in hex\n");
    printf("Normal printf(): ");
    printf("%x\n", 0);

    printf("Fake printf(): ");
    my_printf("%x\n", 0);

    printf("\n");
    // width with x
    printf("width:\n");
    printf("Normal printf(): \n");
    printf("%10x\n", 90);

    printf("fake printf(): \n");
    my_printf("%10x\n", 90);

    printf("\n");
    //width and precision
    printf("width and precision:\n");
    printf("Normal printf(): \n");
    printf("Hello World %10.3s\n", "face");

    printf("Fake printf(): \n");
    my_printf("Hello World %10.3s\n", "face");

    printf("\n");
    // width with zero flag
    printf("width with zero flag:\n");
    printf("Normal printf(): \n");
    printf("%04x\n", 70);

    printf("Fake printf(): \n");
    my_printf("%04x\n", 70);

    printf("\n");
    // precision with x
    printf("precision:\n");
    printf("Normal printf(): \n");
    printf("%5.3x\n", 70);

    printf("Fake printf(): \n");
    my_printf("%5.3x\n", 70);

    printf("\n");
    printf("Normal printf(): \n");
    printf("%3.5x\n", 70);

    printf("Fake printf(): \n");
    my_printf("%3.5x\n", 70);

    printf("\n");
    // uppercase X
    printf("Uppercase X:\n");
    printf("Normal printf(): \n");
    printf("%04X\n",3);

    printf("Fake printf(): \n");
    my_printf("%04X\n",3);

    printf("\n");
    // # flag
    printf("# flag:\n");
    printf("Normal printf(): \n");
    printf("%#5.2x\n", 400);

    printf("Fake printf(): \n");
    my_printf("%#5.2x\n", 400);

    printf("\n");
    // negative with hex
    printf("negative number:\n");
    printf("Normal printf(): \n");
    printf("%5.2x\n", -40);

    printf("Fake printf(): \n");
    my_printf("%5.2x\n", -40);

    // trying all of them together
    printf("\n");
    printf("\n");
    printf("trying them all together:\n");
    printf("Normal printf(): ");
    printf("This is a: %s, This is a number: %d, This is a char: %c\n", "string", 4, 'c');

    printf("Fake printf(): ");
    my_printf("This is a: %s, This is a number: %d, This is a char: %c\n", "string", 4, 'c');

    printf("\n");
    // plus flag with width bigger than precision
    printf("plus flag with width bigger than precision\n");
    printf("Normal printf(): \n");
    printf("%6c   hi %+4.2d\n", 'c', 6);

    printf("Fake printf(): \n");
    my_printf("%6c   hi %+4.2d\n", 'c', 6);

    // custom %m testing
    printf("\n");
    printf("\n");
    printf("Custom my_printf testing:\n");
    printf("\n");
    printf("5+2=7\n");
    printf("Fake printf(): \n");
    my_printf("%m\n", "5+2");

    printf("\n");
    printf("5-2=3\n");
    printf("Fake printf(): \n");
    my_printf("%m\n", "5-2");

    printf("\n");
    printf("5*2=10\n");
    printf("Fake printf(): \n");
    my_printf("%m\n", "5*2");

    printf("\n");
    // custom %b testing
    printf("\n");
    my_printf("%b (5 in binary)\n", 5);
    my_printf("%b (-5 in binary- two's complement) \n", -5);

    printf("\n");
    my_printf("%b (504 in binary)\n", 504);
    my_printf("%b (-504 in binary- two's complement)\n", -504);
    printf("\n");
    my_printf("%b (0 in binary)\n", 0);

    // custom %l testing
    printf("\n");
    printf("length of hello\n");
    my_printf("%l\n", "hello");

    printf("\n");
    my_printf("The length of %s is: %l\n", "hello", "hello");
    my_printf("The length of %s is: %l\n", "hi bye", "hi bye");
    printf("\n");
    // empty string
    my_printf("length of empty string: %l", "");
    return 0;
}