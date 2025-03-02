#include <stdio.h>
#include <math.h>

int main() {
    int n, term, sign, sum = 0;
    printf("Enter the value of N: ");
    scanf("%d", &n);
    sign = -1; // start with a negative sign
    for (int i = 1; i <= n; i++) {
        term = (2 * i - 1); // calculate the value of the term
        sum += sign * pow(term, 3); // add the term to the sum with the appropriate sign
        sign *= -1; // alternate the sign after each term
    }
    printf("The sum of the first %d terms is: %d", n, sum);
    return 0;
}
