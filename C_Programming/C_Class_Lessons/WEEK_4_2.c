//
// Created by adlercohen on 6/23/2022.
//

#include <stdio.h>
int main(){

    float f_num;
    int i_num;

    printf("\n Enter any integer: ");
    scanf("\t%d", &i_num);

    f_num = (float)i_num;

    printf("\nThe floating point variant of %d is = %.3f", i_num, f_num);


    return 0;
}

