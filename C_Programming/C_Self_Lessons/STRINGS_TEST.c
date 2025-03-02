
#include <stdio.h>

int main(){

    char name[30];
    printf("Enter you full name: ");
    fgets(name, sizeof(name), stdin);

    name[0] = 'X';
    printf("%s", name);


    return 0;
}