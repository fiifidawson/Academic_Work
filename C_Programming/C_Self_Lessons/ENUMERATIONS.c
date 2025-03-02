//
// Created by adlercohen on 6/24/2022.
//
// Enum is a type which has fixed set of values
// Integral Constants
// All enum constants are represented as fixed integer vales known as
// integral constants
/*Example
 * By default
 * Small = 0
 * Medium = 1
 * Large = 2
 * ExtraLarge = 3
 */

#include <stdio.h>

enum Size{
    Small,
    Medium,
    Large,
    ExtraLarge,
};

int main(){

    enum Size shoeSize;

    shoeSize = Small;

    // since enum is an integer value, format specifier %d is used
    printf("%d", shoeSize);

    return 0;
}