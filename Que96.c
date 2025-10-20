/*Q96: Reverse each word in a sentence without changing the word order.

/*
Sample Test Cases:
Input 1:
I love coding
Output 1:
I evol gnidoc

*/

#include <stdio.h>
#include <string.h>

void reverseWord(char *start, char *end) {
    char temp;
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    char sentence[200];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    int len = strlen(sentence);
    if(sentence[len - 1] == '\n')
        sentence[len - 1] = '\0';  // Remove trailing newline

    char *word_start = sentence;
    char *temp = sentence;

    while (*temp) {
        if (*temp == ' ') {
            reverseWord(word_start, temp - 1);
            word_start = temp + 1;
        }
        temp++;
    }
    // Reverse the last word
    reverseWord(word_start, temp - 1);

    printf("Output: %s\n", sentence);
    return 0;
}
