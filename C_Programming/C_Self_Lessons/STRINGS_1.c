#include <stdio.h>
int main(){

    char str[20];

    printf("Enter your name: ");

    //If you want to get the entire line as input, use fgets function
    //1st parameter:name of string, 2nd parameter:size of string, 3rd parameter:standard input[taking input]
    fgets(str, sizeof(str), stdin);

    printf("%s", str);

    return 0;
}
