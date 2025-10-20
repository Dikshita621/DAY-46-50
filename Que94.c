/*Q94: Find the longest word in a sentence.

/*
Sample Test Cases:
Input 1:
I love programming
Output 1:
programming

*/

#include <stdio.h>
#include <string.h>

int main() {
    char sentence[200], word[50], longestWord[50];
    int i = 0, j = 0, maxLen = 0, len;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    len = strlen(sentence);
    if (sentence[len-1] == '\n') {
        sentence[len-1] = '\0';  // Remove trailing newline if present
    }

    while (1) {
        j = 0;
        // Extract next word
        while (sentence[i] != ' ' && sentence[i] != '\0') {
            word[j++] = sentence[i++];
        }
        word[j] = '\0';

        // Update longest word if current word length is greater
        if (j > maxLen) {
            maxLen = j;
            strcpy(longestWord, word);
        }

        if (sentence[i] == '\0') {
            break;
        }
        i++;  // Skip space character
    }

    printf("Longest word: %s\n", longestWord);
    return 0;
}
