#include <stdio.h>
#include <conio.h>
int main()
{
    int i;
    float mark, sum = 0, avg, perAvg;

    printf("Enter Marks obtained in 5 Subjects(0 to 100): \n");
    for(i = 0; i < 5; i++){
        scanf("\n%f", &mark);
        sum = sum + mark;
    }
    avg = sum / 5;
    printf("Average Mark = %0.2f", avg);

    perAvg = (sum / 500) * 100;
    printf("\nPercentage obtained: %0.2 percent%", perAvg);

    if(avg >= 80)printf("\n Grade : A");
    else if(avg >= 60)printf("\n Grade : B");
    else if(avg >= 40)printf("\n Grade : C");
    else if(avg < 40)printf("\n Fail ");

    getch();
    return 0;
}