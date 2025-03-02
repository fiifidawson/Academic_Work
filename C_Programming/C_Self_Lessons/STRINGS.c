#include <stdio.h>
int main(){

    char str[] = "Programmer";
    printf("\n%s", str);

    // Taking user input
    char stg[20];
    printf("Enter your name: ");
    scanf(" %s", stg);
    //The scanf takes input until it encounters whitespace in this case
    printf("\n%s", stg);
    return 0;
}