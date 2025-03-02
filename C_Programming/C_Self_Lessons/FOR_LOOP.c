//
// Created by adlercohen on 5/14/2022.
//

// for(InitializationExpression; testExpression; updateExpression){
//code inside the for loop
// }

#include <stdio.h>
int main(){

    //Numbers from 0 to 9
    //for(variable; boolean statement; update)
    //for(int i = 0; i < 10; i++){
    //    printf("%d ", i);
    //}

    //Sum of all numbers from 1 to 100
    int sum = 0;
    for(int n = 1; n <= 100; n++){
        sum = sum + n;
    }
    printf("Sum of all numbers from 1 to 100: %d\n", sum);

    //Sum of even numbers from 1 to 100
    int add = 0;
    for(int e = 1; e <= 100; e = e + 2){
        add = add + e;
    }
    printf("\nSum of all even numbers from 1 to 100: %d", add);

    return 0;
}