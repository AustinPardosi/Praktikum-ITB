#include "boolean.h"
#include "wordmachine.h"
#include "charmachine.h"

int main() {
    STARTWORD();
    int shift = currentWord.Length;

    while(!EndWord) {
        for(int i=0; i<currentWord.Length; i++) {
            char cw = currentWord.TabWord[i];
            cw += shift;
            while ((int)cw > 90) {
                cw -= 26;
            }
            print("%c", cw);
        }
        IgnoreBlanks();
        if (currentChar == MARK) {
            EndWord = true;
            print(".\n");
        } else {
            EndWord = false;
            print(" ");
            CopyWord();
            IgnoreBlanks();
        }
    }

    return 0;
}