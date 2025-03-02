//
// Created by adlercohen on 5/29/2022.
//
/*Create a program to find the largest element of an array using pointers
 *Assign the first element of the array to 'a' largest variable using pointer
    int largest *arr
 * Run a for loop to access each element of the array
 * Compare largest with each array element using pointer
    largest < *(arr + i)
 * If the largest variable is smaller than a element, assign the value to largest
    largest = *(arr + i)
 */

#include <stdio.h>

int main() {
    int arr[5] = {34, 12, 21, 54, 48};

    int largest = *arr;

    for(int i = 1; i < 5; i++) {
        if(largest < *(arr + i)) {
            largest = *(arr + i);
        }
    }
    printf("The largest number is: %d", largest);

    return 0;
}