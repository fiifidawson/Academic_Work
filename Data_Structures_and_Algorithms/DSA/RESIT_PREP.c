//
// Created by adlercohen on 12/10/2022.
//
#include <stdio.h>

int main(){
    int n, arr[15],temp;
    printf("Enter the number of elements in the array:");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        printf("Element %d:", i);
        scanf("%d", &arr[i]);
    }
    printf("\nElements are:");
    for (int i = 0; i < n; ++i) {
        printf("\t%d", arr[i]);
    }
    for (int i = 1; i < n; ++i){
        for (int j = 0; j < n-1; ++j){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("\nArranged elements are:");
    for (int i = 0; i < n; ++i) {
        printf("\t%d", arr[i]);
    }

    return 0;
}