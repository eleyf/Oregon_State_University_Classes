/* CS261- Assignment 1 - Q.5*/
/* Name: Frederick Eley
 * Date: 9/29/17
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch) {
    return ch - 'a' + 'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch) {
    return ch - 'A' + 'a';
}

void sticky(char *word) {
    /*Convert to sticky caps*/
    char letter;
    int i = 0;

    while (word[i] != '\0') {
        letter = word[i];
        if (i % 2 == 0) {
            if (letter >= 'a') {
                word[i] = toUpperCase(letter);
            }
        } else if (letter < 'a') {
            word[i] = toLowerCase(letter);
        }
        i++;
    }

}

int main() {

    char userWord[100];
    /*Read word from the keyboard using scanf*/
    printf("Type in a word to be converted to stickey caps: ");
    scanf("%s", userWord);

    /*Call sticky*/
    sticky(userWord);

    /*Print the new word*/
    printf("The new word is %s\n", userWord);

    return 0;
}
