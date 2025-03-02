#include <stdio.h>

main() {
    double basicSalary;
    printf("Enter your allowance: ");
    scanf("%lf", &basicSalary);

    if(basicSalary > 0){
        // 40% allowance
        double allowance;
        allowance = basicSalary * (0.4);
        printf("\nAllowance GHS: %.2lf", allowance);

        // 20% house rent
        double houseRent;
        houseRent = basicSalary * (0.2);
        printf("\nHouse Rent: %.2lf", houseRent);

        // Net income
        double grossIncome;
        grossIncome = basicSalary + (allowance + houseRent);
        printf("\nNet income: %.2lf", grossIncome);}
    else {
        printf("Invalid Input");
    }
}
