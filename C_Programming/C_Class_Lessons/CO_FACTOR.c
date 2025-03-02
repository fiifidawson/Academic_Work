//
// Created by adlercohen on 4/16/2023.
//
#include<stdio.h>
#include<math.h>
// A = (–1)^i+j  * M
int main()
{
    float a[3][3], cofactor[3][3];
    int i, j, m, n;
    printf("Enter the 9 elements of matrix: ");
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            scanf("%f", &a[i][j]);
    printf("\nThe matrix is\n");
    for(i=0;i<3;i++)
    {
        printf("\n");
        for(j=0;j<3;j++)
            printf("%f\t",a[i][j]);
    }
    // Finding cofactor
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            m = 0;
            n = 0;
            float temp[2][2];
            for(int row=0; row<3; row++)
            {
                for(int col=0; col<3; col++)
                {
                    if(row != i && col != j){
                        temp[m][n] = a[row][col];
                        if(n < 1)
                            n++;
                        else
                        {
                            n = 0;
                            m++;
                        }
                    }
                }
            }
            cofactor[i][j] = pow(-1, i+j) * ((temp[0][0]*temp[1][1]) - (temp[0][1]*temp[1][0]));
        }
    }
    printf("\n\nCofactor matrix is: \n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            printf("%f\t",cofactor[i][j]);
        printf("\n");
    }
    return 0;
}
