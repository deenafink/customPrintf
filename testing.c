#include <stdio.h>

void my_printf(const char *format, ...);

int main() {
    // d
    printf("d testing:\n");
    // text with numbers
    printf("text with numbers:\n");
    printf("Normal printf(): ");
    printf("Hello World %d\n", 10001);

    printf("Fake printf(): ");
    my_printf("Hello World %d\n", 10001);

    // text with numbers and chars
    printf("with numbers and chars\n");
    printf("text with numbers and chars:\n");
    printf("Normal printf(): ");
    printf("Hello World %d what is your age %d\n", 'f', 3);

    printf("Fake printf(): ");
    my_printf("Hello World %d what is your age %d\n", 'f', 3);

    // %d with 0
    printf("with 0 edgecase:\n");
    printf("Normal printf(): ");
    printf("Hello World %d\n", 0);

    printf("Fake printf(): ");
    my_printf("Hello World %d\n", 0);

    // %d with negative number
    printf("negative number:\n");
    printf("Normal printf(): ");
    printf("Hello World %d\n", -55);

    printf("Fake printf(): ");
    my_printf("Hello World %d\n", -55);

    // %d with positive flag
    printf("+ flag:\n");
    printf("Normal printf(): ");
    printf("Hello World %+d\n", 55);

    printf("Fake printf(): ");
    my_printf("Hello World %+d\n", 55);

    // using precision flag with %d // should add four zeroes
    printf("precision:\n");
    printf("Normal printf(): \n");
    printf("%.5d\n", 70);

    printf("Fake printf(): \n");
    my_printf("%.5d\n", 70);

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

    // precision is larger than width
    printf("precision is larger than width:\n");
    printf("Normal printf(): \n");
    printf("%2.6d\n", 84);

    printf("Fake printf(): \n");
    my_printf("%2.6d\n", 84);

    // plus flag with negatvie number
    printf("plus flag with negative number (don't print it)\n");
    printf("Normal printf(): \n");
    printf("%+d\n", -555);

    printf("Fake printf(): \n");
    my_printf("%+d\n", -555);

     // deal with flags with width becasue they need to be included if adding extra chars
    printf("flags and width becayse they need to be included if addingn extra chars:\n");
    printf("Normal printf(): \n");
    printf("%+2d\n", 555);

    printf("Fake printf(): \n");
    my_printf("%+2d\n", 555);

    // negative number with width
    printf("negartive number with width:\n");
    printf("Normal printf(): \n");
    printf("%6d\n", -400);

    printf("Fake printf(): \n");
    my_printf("%6d\n", -400);

    // plus flag with width
    printf("plus flag with width:\n");
    printf("Normal printf(): \n");
    printf("%+4d\n", 6);

    printf("Fake printf(): \n");
    my_printf("%+4d\n", 6);
    
    // plus sign but negative with width
    printf("Plus sign, negative number, with width:\n");
    printf("Normal printf(): \n");
    printf("%+4d\n", -6);

    printf("Fake printf(): \n");
    my_printf("%+4d\n", -6);

    // left alignemnt flag with precision involved
    printf("left alignment, precision too:\n");
    printf("Normal printf(): \n");
    printf("|%-10.3d|\n", 42);    

    printf("Fake printf(): \n");
    my_printf("|%-10.3d|\n", 42);

    // left alignment without precision involved
    printf("left alignment, no precision:\n");
    printf("Normal printf(): \n");
    printf("|%-10d|\n", 42);    

    printf("Fake printf(): \n");
    my_printf("|%-10d|\n", 42);

    // width with zero flag
    printf("width with zero flag:\n");
    printf("Normal printf(): \n");
    printf("%04d\n", 7);

    printf("Fake printf(): \n");
    my_printf("%04d\n", 7);

    // with text embedded
    printf("with text embedded:\n");
    printf("Normal printf(): \n");
    printf("Hello World %10d whats up\n", 689);

    printf("Fake printf(): \n");
    my_printf("Hello World %10d whats up\n", 689);

    //checking with the star*
    printf("with the *:\n");
    printf("Normal printf(): \n");
    printf("%*d\n", 10, 10);

    printf("fake printf(): \n");
    my_printf("%*d\n", 10, 10);

    // %c testing
    printf("\n");
    printf("c testing:\n");

    printf("Normal printf(): ");
    printf("Hello World %c\n", 'c');

    printf("Fake printf(): ");
    my_printf("Hello World %c\n", 'c');

    // c testing with width
    printf("c testing with width:\n");
    printf("Normal printf(): \n");
    printf("Hello World %10c\n", 'f');

    printf("Fake printf(): \n");
    my_printf("Hello World %10c\n", 'f');

    // left alignment with c
    printf("left alignment:\n");
    printf("Normal printf(): \n");
    printf("|%-10c|\n", 'c');    

    printf("Fake printf(): \n");
    my_printf("|%-10c|\n", 'c');

    // s
    printf("\n");
    printf("s testing:\n");

    printf("Normal printf(): \n");
    printf("%s\n", "hello");    

    printf("Fake printf(): \n");
    my_printf("%s\n", "hello");

    printf("Normal printf(): ");
    printf("Hello World %s\n", "string");

    printf("Fake printf(): ");
    my_printf("Hello World %s\n", "string");

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

    //left with s
    printf("left alignment:\n");
    printf("Normal printf(): \n");
    printf("%-10s\n", "left");    

    printf("Fake printf(): \n");
    my_printf("%-10s\n", "left");

    // precision
    printf("with precision:\n");
    printf("Normal printf(): \n");
    printf("%.*s\n", 3, "abcdef");

    printf("Fake printf(): \n");
    my_printf("%.*s\n", 3, "abcdef");

    // %x testing
    printf("\n");
    printf("x testing:\n");

    printf("Normal printf(): \n");
    printf("%x\n", 2454);    

    printf("Fake printf(): \n");
    my_printf("%x\n", 2454);

    printf("Normal printf(): ");
    printf("Hello World %x\n", 26);

    printf("Fake printf(): ");
    my_printf("Hello World %x\n", 26);

    printf("Normal printf(): ");
    printf("%x\n", 689);

    printf("Fake printf(): ");
    my_printf("%x\n", 689);

    // width with x
    printf("width:\n");
    printf("Normal printf(): \n");
    printf("%10x\n", 90);

    printf("fake printf(): \n");
    my_printf("%10x\n", 90);

    //width and precision
    printf("width and precision:\n");
    printf("Normal printf(): \n");
    printf("Hello World %10.3s\n", "face");

    printf("Fake printf(): \n");
    my_printf("Hello World %10.3s\n", "face");

    // width with zero flag
    printf("width with zero flag:\n");
    printf("Normal printf(): \n");
    printf("%04x\n", 70);

    printf("Fake printf(): \n");
    my_printf("%04x\n", 70);

    // precision with x
    printf("precision:\n");
    printf("Normal printf(): \n");
    printf("%5.3x\n", 70);

    printf("Fake printf(): \n");
    my_printf("%5.3x\n", 70);

    printf("Normal printf(): \n");
    printf("%3.5x\n", 70);

    printf("Fake printf(): \n");
    my_printf("%3.5x\n", 70);

    // uppercase X
    printf("Uppercase X:\n");
    printf("Normal printf(): \n");
    printf("%04X\n",3);

    printf("Fake printf(): \n");
    my_printf("%04X\n",3);

    // # flag
    printf("# flag:\n");
    printf("Normal printf(): \n");
    printf("%#5.2x\n", 400);

    printf("Fake printf(): \n");
    my_printf("%#5.2x\n", 400);

    // negative with hex
    printf("negative number:\n");
    printf("Normal printf(): \n");
    printf("%5.2x\n", -40);

    printf("Fake printf(): \n");
    my_printf("%5.2x\n", -40);

    // trying all of them together
    printf("\n");
    printf("trying them all together:\n");
    printf("Normal printf(): ");
    printf("This is a: %s, This is a number: %d, This is a char: %c\n", "string", 4, 'c');

    printf("Fake printf(): ");
    my_printf("This is a: %s, This is a number: %d, This is a char: %c\n", "string", 4, 'c');

    // plus flag with width bigger than precision
    printf("Normal printf(): \n");
    printf("%6c   hi %+4.2d\n", 'c', 6);

    printf("Fake printf(): \n");
    my_printf("%6c   hi %+4.2d\n", 'c', 6);

    // custom %m testing
    printf("\n");
    printf("Custom my_printf testing:\n");
    printf("Fake printf(): \n");
    my_printf("%m\n", "5+2");

    printf("Fake printf(): \n");
    my_printf("%m\n", "5-2");

    printf("Fake printf(): \n");
    my_printf("%m\n", "5*2");

    return 0;
}