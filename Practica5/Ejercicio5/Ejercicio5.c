
/* 5. Corregir los errores en el siguiente código manualmente, el cual carga una cola y luego calcula y
muestra la suma de sus elementos.

#include <stdio.h>
#include "tdacola.h"
void leerCola(TCOLA *c);

int main(void) {
    TCOLA cola;
    TELEMENTOC n, suma;
    iniciac(cola); //No pasa la direccion de memoria de cola
    leerCola(&cola);
    suma == 0; 

    while(!vaciac(*cola)) { //pone como puntero a cola
        sacac(cola, &n); //no manda la direccion de memoria de cola
        suma -= n; //No esta sumando
    }
    printf("%d", suma);
    return 0;
}
void leerCola(TCOLA *c) {
    TELEMENTOC n;
    iniciac(&c); //vulve a iniciar C y manda una direccion de memoria y no simplemente C
    while(scanf("%d", n)) //No tiene condicion de corte y se olvida el &
        ponec(c, &n); //mal el poner la direccion de memoria de n, cuando requiere n solamente
} 
*/

#include <stdio.h>
#include "tdacola.h"
void leerCola(TCOLA *c);

int main(void) {
    TCOLA cola;
    TELEMENTOC n, suma = 0;
    iniciac(&cola); 
    leerCola(&cola);

    while(!vaciac(cola)){ 
        sacac(&cola, &n);
        suma += n;
    }
    printf("%d\n", suma);
    return 0;
}
void leerCola(TCOLA *c) {
    TELEMENTOC n;
    while(scanf("%d", &n) && n != 0)
        ponec(c, n);
}