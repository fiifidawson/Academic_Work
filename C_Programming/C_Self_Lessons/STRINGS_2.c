#include <stdio.h>
int main(){

    char str[] = "Programmer";

    printf("%c\n", str[0]);
    printf("%c\n", str[1]);
    printf("%c\n", str[2]);
    printf("%c\n", str[3]);

    // Changing characters of a string
    str[1] = "l";

    return 0;
}