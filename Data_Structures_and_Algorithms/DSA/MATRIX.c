//
// Created by adlercohen on 11/30/2022.
//
#include<stdio.h>
int a[3][3],i,j,m,n,det=0;
int main(){
    printf("Please Enter the Number of ROWS:\t");
    scanf("%d",&m);
    printf("Please Enter the Number of COLUMNS:\t");
    scanf("%d",&n);
    for(i=0;i<m;i++)
        for(j=0;j<n;j++){
            printf("\nPlease Enter the Elements[%d][%d]:\t",i,j);
            scanf("%d",&a[i][j]);
        }
    for(i=0;i<m;i++){
        printf("\n");
        for(j=0;j<n;j++)
            printf("\t%d",a[i][j]);
    }
    i=0;
    for(j=0;j<n;j++)
        det = det+a[i][j]*(a[i+1][(j+1)%3]*a[i+2][(j+2)%3] - a[i+1][(j+2)%3]*a[i+2][(j+1)%3]);
    printf("\nThe Determinant: %d",det);
}
