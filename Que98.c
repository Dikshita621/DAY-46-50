/*Q98: Print initials of a name with the surname displayed in full.

/*
Sample Test Cases:
Input 1:
John David Doe
Output 1:
J.D. Doe

*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char name[100];
    int i = 0;

    printf("Enter a full name: ");
    fgets(name, sizeof(name), stdin);

    // Remove trailing newline if present
    name[strcspn(name, "\n")] = '\0';

    // Print first initial
    if (name[0] != '\0') {
        printf("%c.", toupper(name[0]));
    }

    // Print initials of middle names (if any) and store index of surname start
    int lastSpaceIndex = -1;
    for (i = 0; name[i] != '\0'; i++) {
        if (name[i] == ' ') {
            // Print initial of the next word if not the last word
            if (name[i+1] != '\0' && strchr(name + i + 1, ' ') != NULL) {
                printf("%c.", toupper(name[i+1]));
            }
            lastSpaceIndex = i;
        }
    }

    // Print surname (substring after last space)
    if (lastSpaceIndex != -1) {
        printf(" %s", &name[lastSpaceIndex + 1]);
    } else {
        // If no spaces, whole name is single word (surname)
        // Already printed first initial, print rest as is
        printf("%s", &name[1]);
    }

    printf("\n");
    return 0;
}
