//
// Created by adlercohen on 5/14/2022.
//

/*POINTS
 * A while loop without an exit statement continues to run until
 * memory runs out
 *
 */
#include <stdio.h>
int main() {

    //Basic structure of while loop
    int count = 1;
    while (count < 5) {
        printf("while loop in C\n");
        printf("Count: %d\n", count);
        count = count + 1;

        return 0;
    }
}