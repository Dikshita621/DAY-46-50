/*Q99: Change the date format from dd/04/yyyy to dd-Apr-yyyy.

/*
Sample Test Cases:
Input 1:
15/04/2025
Output 1:
15-Apr-2025

*/

#include <stdio.h>
#include <string.h>

int main() {
    char date[20], day[3], month[3], year[5];

    printf("Enter date (dd/04/yyyy): ");
    fgets(date, sizeof(date), stdin);

    // Extract day, month and year substrings
    strncpy(day, date, 2);
    day[2] = '\0';

    strncpy(month, date + 3, 2);
    month[2] = '\0';

    strncpy(year, date + 6, 4);
    year[4] = '\0';

    // Check if month is "04"
    if (strcmp(month, "04") == 0) {
        printf("%s-Apr-%s\n", day, year);
    } else {
        printf("Input month is not 04.\n");
    }

    return 0;
}
