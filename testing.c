#include <stdio.h>

void my_printf(const char *format, ...);

int main() {
    printf("Normal printf(): ");
    printf("Hello World %d\n", 10001);

    printf("Fake printf(): ");
    my_printf("Hello World %d\n", 10001);

    printf("Normal printf(): ");
    printf("Hello World %d what is your age %d\n", 'f', 3);

    printf("Fake printf(): ");
    my_printf("Hello World %d what is your age %d\n", 'f', 3);

    printf("Normal printf(): ");
    printf("Hello World %d\n", 0);

    printf("Fake printf(): ");
    my_printf("Hello World %d\n", 0);

    printf("Normal printf(): ");
    printf("Hello World %d\n", -55);

    printf("Fake printf(): ");
    my_printf("Hello World %d\n", -55);

    printf("Normal printf(): ");
    printf("Hello World %+d\n", 55);

    printf("Fake printf(): ");
    my_printf("Hello World %+d\n", 55);

    // c
    printf("Normal printf(): ");
    printf("Hello World %c\n", 'c');

    printf("Fake printf(): ");
    my_printf("Hello World %c\n", 'c');

    // s
    printf("Normal printf(): ");
    printf("Hello World %s\n", "string");

    printf("Fake printf(): ");
    my_printf("Hello World %s\n", "string");

    // trying all of them together
    printf("Normal printf(): ");
    printf("This is a: %s, This is a number: %d, This is a char: %c\n", "string", 4, 'c');

    printf("Fake printf(): ");
    my_printf("This is a: %s, This is a number: %d, This is a char: %c\n", "string", 4, 'c');

    // x
    printf("Normal printf(): ");
    printf("Hello World %x\n", 26);

    printf("Fake printf(): ");
    my_printf("Hello World %x\n", 26);

    printf("Normal printf(): ");
    printf("Hello World %x\n", 689);

    printf("Fake printf(): ");
    my_printf("Hello World %x\n", 689);

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

    // // width with x
    printf("Normal printf(): \n");
    printf("%10x\n", 90);

    printf("fake printf(): \n");
    my_printf("%10x\n", 90);

    ////checking with the star*
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
    printf("|%-10.3d|\n", 42);    

    printf("Fake printf(): \n");
    my_printf("|%-10.3d|\n", 42);

    // left comparison without precision involved
    printf("Normal printf(): \n");
    printf("|%-10d|\n", 42);    

    printf("Fake printf(): \n");
    my_printf("|%-10d|\n", 42);

    // left with c
    printf("Normal printf(): \n");
    printf("|%-10c|\n", 'c');    

    printf("Fake printf(): \n");
    my_printf("|%-10c|\n", 'c');

    //left with s
    printf("Normal printf(): \n");
    printf("%-10s\n", "left");    

    printf("Fake printf(): \n");
    my_printf("%-10s\n", "left");

    // left with s
    printf("Normal printf(): \n");
    printf("%10s\n", "right");    

    printf("Fake printf(): \n");
    my_printf("%10s\n", "right");

    printf("Normal printf(): \n");
    printf("%d\n", 5);    

    printf("Fake printf(): \n");
    my_printf("%d\n", 5);

    printf("Normal printf(): \n");
    printf("%c\n", 'c');    

    printf("Fake printf(): \n");
    my_printf("%c\n", 'c');

    printf("Normal printf(): \n");
    printf("%d\n", 5);    

    printf("Fake printf(): \n");
    my_printf("%d\n", 5);

    printf("Normal printf(): \n");
    printf("%s\n", "choja");    

    printf("Fake printf(): \n");
    my_printf("%s\n", "choja");

    printf("Normal printf(): \n");
    printf("%x\n", 2454);    

    printf("Fake printf(): \n");
    my_printf("%x\n", 2454);

    printf("Fake printf(): \n");
    my_printf("%m\n", "5+2");

    printf("Fake printf(): \n");
    my_printf("%m\n", "5-2");

    printf("Fake printf(): \n");
    my_printf("%m\n", "5*2");

    return 0;
}