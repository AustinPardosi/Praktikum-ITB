#include <stdio.h>
#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"

int main() {
    STARTWORD();
    int shift = currentWord.Length;
    while (!EndWord) {
        for(int i=0; i<currentWord.Length;  i++) {
            char cw = currentWord.TabWord[i];
            cw += shift;
            while ((int) cw > 90) {
                cw -= 26;
            }
            printf("%c", cw);
        }
        IgnoreBlanks();
        if(currentChar == MARK) {
            EndWord = true;
            printf(".\n");
        } else {
            printf(" ");
            CopyWord();
            IgnoreBlanks();
        }
    }

    return 0;
}