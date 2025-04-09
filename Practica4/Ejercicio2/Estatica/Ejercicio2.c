#include <stdio.h>
#include "funciones.h"
/* 2. Desarrollar un TDA que represente la idea de “texto”. En C no existe este tipo básico, con lo
cual las aplicaciones siempre quedan acopladas a la idea de que un string es una cadena de
caracteres, por lo que se manejan con punteros y posiciones. Realizar una implementación
estática y una dinámica. Analizar la manera de trabajar con la longitud del texto evitando tener
que almacenar el carácter '\0'. Las operaciones que deberá soportar el TDA son (se propone no
utilizar funciones strxxx):
◦ crear(char* c) retorna Texto
◦ destruir(Texto t) sin valor de retorno. Libera la memoria reservada en crear.
◦ tamaño(Texto t) retorna entero.
◦ imprimir(Texto t) (por pantalla)
◦ imprimirArch(Texto t, FILE* arch)
◦ caracterEn(Texto texto, entero posición) retorna caracter.
◦ concatenar(Texto t1, Texto t2) retorna Texto.
◦ reemplazar(Texto texto, char caracter, char nuevoCaracter) retorna Texto.
Ej: reemplazar('Balsa', 'a', 'o') >> 'Bolso'
◦ subTexto(Texto texto, entero desde, entero hasta) retorna Texto.
Ej: subTexto('HolaMundo', 4, 7) retorna 'Mun'
◦ comienzaCon(Texto texto, Texto prefijo) retorna entero|booleano.
◦ terminaCon(Texto texto, Texto sufijo) retorna entero|booleano. */

void main(){
    Texto t, t2;
    FILE *arch;
    t = crear("Hola mundo");
    printf("El tamanio es: %d\n", tamanio(t));
    imprimir(t);

    imprimirArch(t,arch);

    printf("Caracter de la posicion %d es: %c \n", 5,caracterEn(t,5));
    t2 = crear(". como andan?");
    
    t = concatenar(t, t2);
    imprimir(t);
    destruir(t2);
    imprimir(t2);
    
    t = reemplazar(t,'o','a');
    imprimir(t);

    t = subTexto(t,3,12);
    imprimir(t);
    
    t2 = crear(". ");
    
    if (comienzaCon(t, t2)){
        printf("Comienza con ");
        imprimir(t2);
    } else {
        printf("No comienza con ");
        imprimir(t2);
    }
    
    if (terminaCon(t, t2)){
        printf("Termina con ");
        imprimir(t2);
    } else {
        printf("No termina con ");
        imprimir(t2);
    }
    
    
}