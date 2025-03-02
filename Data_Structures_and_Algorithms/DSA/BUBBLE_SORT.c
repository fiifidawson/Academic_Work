//
// Created by adlercohen on 11/30/2022.
//
#include<stdio.h>
int main()
{
    int a[15],i,n,j,temp;
    printf("Please Enter the Number of Elements to be Entered:\t");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\nPlease Enter Element %d:",i+1);
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
        printf("\nTheElement: a[%d]: %d",i,a[i]);

    for(i=1;i<n;i++){
        for(j=0;j<n-i;j++){
            if(a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    for(i=0;i<n;i++)
        printf("\nTheElement:a[%d]:%d",i,a[i]);
    return 0;
}
