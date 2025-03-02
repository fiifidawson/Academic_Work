//
// Created by adlercohen on 8/18/2022.
//
#include<stdio.h>
#include<math.h>
int OctalToDecimal(int n) {
    int p = 0, decimal = 0, r;

    while(n>0){

        // retrieving the right-most digit of n
        r = n % 10;

        // dividing n by 10 to remove the
        // right-most digits since it is already
        // scanned in previous step
        n = n / 10;

        decimal = decimal + r * pow( 8 , p );
        ++p;

    }

    return decimal;
}
int main() {
    int n, i, k;
    printf("Enter Octal: ");
    scanf("%d", &n);
    printf("\nDecimal of Octal Number %d is : %d", n, OctalToDecimal(n));
    return 0;
}