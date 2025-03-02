//
// Created by adlercohen on 11/30/2022.
//
#include <stdio.h>

int main(){

    int n, i, j, arr[20], temp;

    printf("Enter the number of elements in the array:");
    scanf("%d", &n);

    printf("\nEnter the elements into the array:\n");
    for (i = 0; i < n; ++i) {
        printf("Element %d:", i+1);
        scanf("%d", &arr[i]);
    }
    printf("\nEntered elements:");
    for (i = 0; i < n; ++i){
        printf("\t%d", arr[i]);
    }
    //Algorithm for bubble sort

    for ( i = 1; i < n; ++i) {
        for ( j = 0; j < n-1; ++j) {
            if (arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] =temp;
            }
        }
    }
    printf("\nSorted array:");
    for (i = 0; i < n; ++i){
        printf("\t%d", arr[i]);
    }

    //Binary search
    int low = 0, high = n-1, mid, num, flag = 0;
    printf("\nEnter the number to be searched:");
    scanf("%d", &num);

    for (i = 0; i < n; ++i) {
        mid = (high+low)/2;
        if (num == arr[mid]){
            flag = 1;
            break;
        }
        else if(num > arr[mid]){
            low = mid + 1;
            continue;
        }
        else {
            high = mid -1;
            continue;
        }
    }
    if(flag == 1){
        printf("\nNumber %d\nfound at index: %d", arr[mid], mid);
    }
    else{
        printf("\nNumber not found");
    }

    return 0;

}