/*Q97: Print the initials of a name.

/*
Sample Test Cases:
Input 1:
John Doe
Output 1:
J.D.

*/

#include <stdio.h>
#include <ctype.h>

int main() {
    char name[100];
    int i = 0;

    printf("Enter a name: ");
    fgets(name, sizeof(name), stdin);

    // Print the first initial if it exists
    if (name[0] != '\0' && name[0] != '\n') {
        printf("%c.", toupper(name[0]));
    }

    // Loop through the string to find spaces and print next character as initial
    while (name[i] != '\0') {
        if (name[i] == ' ' && name[i+1] != ' ' && name[i+1] != '\0' && name[i+1] != '\n') {
            printf("%c.", toupper(name[i+1]));
        }
        i++;
    }

    printf("\n");
    return 0;
}
