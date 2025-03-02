//
// Created by adlercohen on 7/28/2022.
//
//#include <stdio.h>
//int main(){ int arr[2][3] = {{0, 1, 2}, {3, 4, 5}};
//    //accessing first array and first value of first array
//    printf("%d\n", arr[0][0]);
//    //accessing first array and second value of first array
//    printf("%d\n", arr[0][1]);
//    //accessing first array and third value of first array
//    printf("%d\n", arr[0][2]);
//    //accessing second array and first value of first array
//    printf("%d\n", arr[1][0]);
//    //accessing second array and second value of first array
//    printf("%d\n", arr[1][1]);
//    //accessing second array and third value of first array
//    printf("%d\n", arr[1][2]);
//    return 0;
//}

#include <stdio.h>
int main(){ int arr[2][3] = {{0, 1, 2}, {3, 4, 5}};
    // First for loop iterates two times from i = 0 to i = 1 to access the two inner
    // of the 2-dimensional array
    for(int i = 0; i < 2; ++i)
    { // Inner for loop iterates three times from j = 0 to j = 2 to access the
    // three elements in both of the two sub arrays
    for (int j = 0; j < 3; ++j){
        printf("%d ", arr[i][j]); } printf("\n"); }
    return 0;
}