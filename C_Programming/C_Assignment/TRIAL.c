//
// Created by adlercohen on 7/27/2022.
//

#include<stdio.h>
int main(){
    int a[3][3], n, i, j, det= 0;
    printf("Enter the number of values:");
    scanf("%d", &n);

    for(i  = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("Arr[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    det = (a[0][0]*(a[1][1]*a[2][2]-a[1][2]*a[2][1])) -
            (a[0][1]*(a[1][0]*a[2][2]-a[2][0]*a[1][2])) +
            (a[0][2]*(a[1][0]*a[2][1]-a[2][0]*a[1][1]));

    printf("\nThe determinant is %d", det);

    return 0;
}

//int x=10;
//char ch = 'A';
//void *gp;
//gp = &x;
//printf("\n Generic pointer points to the integer value = %d", *(int*)gp);
//gp = &ch;
//printf("\n Generic pointer now points to the character= %c", *(char*)gp);