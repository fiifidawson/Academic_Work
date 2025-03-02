//
// Created by adlercohen on 6/25/2022.
//
//Create a new file in write mode
/*Write Content
 * C is a fun programming language
 * And, I love using C language
 *Close the file
 *Again open the file in read mode and read the content of the file
 */
#include <stdio.h>

int main() {

    FILE* fileptr;

    fileptr = fopen("file.txt", "w");
    fputs("C is a fun programming language\n", fileptr);
    fputs("I love using C language", fileptr);

    fclose(fileptr);

    fileptr = fopen("file.txt", "r");
    char content[1000];

    if(fileptr != NULL) {
        while(fgets(content, 1000, fileptr)) {
            printf("%s", content);
        }
    }

    else {
        printf("File reading is unsuccessful");
    }

    fclose(fileptr);

    return 0;
}