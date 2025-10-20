/*Q95: Check if one string is a rotation of another.

/*
Sample Test Cases:
Input 1:
abcde
deabc
Output 1:
Rotation

Input 2:
abc
acb
Output 2:
Not rotation

*/

#include <stdio.h>
#include <string.h>

// Function to check if s2 is a rotation of s1
int isRotation(char* s1, char* s2) {
    // Check length first
    if (strlen(s1) != strlen(s2)) {
        return 0;
    }

    // Create a new string which is s1 concatenated with itself
    char temp[200];
    strcpy(temp, s1);
    strcat(temp, s1);

    // Check if s2 is a substring of temp
    if (strstr(temp, s2) != NULL) {
        return 1;
    }
    return 0;
}

int main() {
    char str1[100], str2[100];

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);

    // Remove trailing newline characters
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    if (isRotation(str1, str2)) {
        printf("Rotation\n");
    } else {
        printf("Not rotation\n");
    }

    return 0;
}
