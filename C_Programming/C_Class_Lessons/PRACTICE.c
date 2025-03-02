//
// Created by adlercohen on 8/27/2022.
//
#include <stdio.h>
int main(){

    int n, i, j, det = 0, arr[3][3];
    printf("Enter the number of rows and columns:");
    scanf("%d", &n);

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            printf("a[%d][%d]:", i,j);
            scanf("%d", &arr[i][j]);
        }



    }
    return 0;
}
