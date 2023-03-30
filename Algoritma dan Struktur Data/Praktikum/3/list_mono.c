#include <stdio.h>
#include <stdlib.h>
#include "liststatik.h"
#include "boolean.h"

int main() {
    boolean isStatic, isAscending, isDecending;
    ListStatik L;
    readList(&L);

    isStatic = true; 
    isAscending = true;
    isDecending = true;

    int i = 1;
    while((isAscending == true | isDecending == true) && i<listLength(L)){
        if (ELMT(L,i) < ELMT(L,i-1)) {
            isAscending = false;
        }
        if (ELMT(L,i) > ELMT(L,i-1)) {
            isDecending = false;
        }
        if (ELMT(L,i) != ELMT(L,i-1)) {
            isStatic = false;
        }
        i++;
    }
    
    if (isStatic == true) {
        printf("Static Monotic List\n");
    } else if (isAscending == true) {
        printf("Non-decending Monotic List\n");
    } else if (isDecending == true) {
        printf("Non-ascending Monotic List\n");
    } else {
        printf("Non-monotic List\n");
    }
    return 0;
}