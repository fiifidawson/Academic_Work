// This program checks if a character is an alphabet, digit or special symbol
#include <stdio.h>

int main() {
    char user_input;
    // Taking user input
    printf("Enter a user_input: ");
    scanf("%c", &user_input);

    // ASCII: Checking whether the user_input is an alphabet i.e upper case or lower case
    if ((user_input >= 'a' && user_input <= 'z') || (user_input >= 'A' && user_input <= 'Z')) {
        printf("%c is an alphabet", user_input);
        }

    // ASCII: Checking whether the user_input is a number
    // Downside: Negative numbers are not affected
    else if (user_input >= '0' && user_input <= '9') {
        printf("%c is a digit", user_input);
    }
    // If user_input is a special symbol
    else {
        printf("%c is a special symbol", user_input);
    }
    return 0;
}
