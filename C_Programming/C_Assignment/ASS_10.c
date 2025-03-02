//
// Created by adlercohen on 7/6/2022.
//
#include <stdio.h>

int main(){
    
    double totalSellingPrice, profit, totalCostPrice, costItem;

    printf("Enter the total selling price of the 15 items:");
    scanf("%lf", &totalSellingPrice);

    printf("\nEnter the profit:");
    scanf("%lf", &profit);

    totalCostPrice = totalSellingPrice - profit;
    printf("\nTotal cost price: %.2lf", totalCostPrice);

    costItem = totalSellingPrice / 15;

    printf("\nCost price of each item: %.2lf", costItem);
    
    return 0;
}