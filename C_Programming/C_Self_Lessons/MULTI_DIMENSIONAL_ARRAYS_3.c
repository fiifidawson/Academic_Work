//
// Created by adlercohen on 5/25/2022.
//
// MULTI DIMENSIONAL ARRAY FOR LOOP

#include <stdio.h>
int main(){
    
    int arr[2][3] = {{0, 1, 2}, {3, 4, 5}};

    // First for loop iterates two times from i = 0 to i = 1 to access the two inner
    // of the 2-dimensional array
    for(int i = 0; i < 2; ++i){
        // Inner for loop iterates three times from j = 0 to j = 2 to access the
        // three elements in both of the two sub arrays
        for (int j = 0; j < 3; ++j) {

            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}