//
// Created by adlercohen on 8/18/2022.
//
#include <stdio.h>
#include <conio.h>

int main()
{
    int a[3][3],b[3][3],c[3][3],i,j,k,m,n;
    printf("Please Enter the Number of ROWS:\t");
    scanf("%d",&m);
    printf("Please Enter the Number of COLUMN:\t");
    scanf("%d",&n);
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        {
            printf("\nPlease Enter the Element for MATRIX A[%d][%d]:\t",i,j);
            scanf("%d",&a[i][j]);
        }
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        {

            printf("\nPlease Enterthe Elementafor MATRIX B[%d][%d]:\t",i,j);
            scanf("%d",&b[i][j]);
        }
    getch();
    printf("\nThe Elements of MATRIX A:\n");
    for(i=0;i<3;i++)
    {
        printf("\n");
        for(j=0;j<3;j++)

            printf("\t%d",a[i][j]);
    }
    getch();
    printf("\nThe Elements of MATRIX B:\n");
    for(i=0;i<3;i++)
    {
        printf("\n");
        for(j=0;j<3;j++)

            printf("\t%d",b[i][j]);
    }
    getch();
    printf("\nThe Matrix Multiplication:");
    for(i=0;i<3;i++)
        for (j=0;j<3;j++)
            c[i][j]=0;
    for(i=0;i<3;i++)
    {
        printf("\n");
        for(j=0;j<3;j++)
            for(k=0;k<3;k++)
                c[i][j]=c[i][j]+a[i][k]*b[k][j];
    }
    for(i=0;i<3;i++)
    {
        printf("\n");
        for(j=0;j<3;j++)
            printf("\t%d",c[i][j]);
    }
}
