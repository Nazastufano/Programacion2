#include <stdio.h>

/*9. Reescribir las siguientes sentencias utilizando la instrucción switch:

If (x == 4)
    y = 7;
else 
    if (x == 5)
        y = 9;
    else
        if(x == 9)
            y = 14;
        else
            y = 22;
*/
void main () {
    int x, y;
    switch (x) {
    case 4:
        y = 7;
        break;
    case 5:
        y = 9;
        break;
    case 9:
        y = 14;
        break;
    default:
        y = 22;
        break;
    }
}