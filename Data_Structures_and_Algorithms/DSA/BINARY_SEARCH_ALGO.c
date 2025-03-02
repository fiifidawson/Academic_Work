//
// Created by adlercohen on 12/6/2022.
//
#include<stdio.h>
int main()
{
    int c,first,last,middle,n,search,a[5],i,j,key,temp, flag=0;
    printf("Please Enter the Number[] of Elements to be Entered:\t");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\nEnter Element %d:",i+1);
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
        printf("\nTheElement:a[%d]: %d", i+1, a[i]);
    printf("\n======================================");

    for(i=1;i<n;i++){
        for(j=0;j<n-i;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("\nElements are in ORDER:");
    for(i=0;i<n;i++)
        printf("\nTheElement:a[%d]:%d", i+1, a[i]);


    printf("\nPlease Enter the Key to be Searched:");
    scanf("%d",&key);
    printf("\nKey:%d",key);
    int low=0,high=n-1,mid;
    for(i=0;i<n;i++){
        mid=(low+high)/2;
        if(key==a[mid]){
            //Value is key
            flag=1;
            break;
        }
        else
        if(key>a[mid]){
            low=mid+1;
            continue;
        }
        else{
            high=mid-1;
            continue;
        }
    }
    if(flag==1)
        printf("\nkey found at INDEX %d", mid+2);
    else
        printf("\nkey not found");
}
//,
//a[mid]