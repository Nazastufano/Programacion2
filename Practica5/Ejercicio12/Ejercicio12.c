#include "TDAPila.h"
#include "TDACola.h"
#include <stdio.h>
/* 12. Desarrollar un programa que reciba una expresión aritmética que contemple las cuatro
operaciones básicos (+, -, * y /) en notación postfija (polaca invertida) y devuelva su valor, a
menos que ocurra un error porque la expresión no sea válida. Las expresiones postfijas no
necesitan paréntesis para especificar el orden de las operaciones. Ej: 5 *(1+3) en notación
posfija es 5 1 3 + *. Los operandos se limitan a números de un solo dígito y son leídos como
caracteres, de la misma manera que los operadores. */

void cargaC(TCola *);
void resultadoOperacion(TCola *);
void main(){
    TCola C;
    iniciaC(&C);
    cargaC(&C);

    resultadoOperacion(&C);
}

void cargaC(TCola *C){
    TElementoC elem;

    do {
        do {
            printf("Ingrese el elemento a almacenar (. terminar)\n");
            scanf(" %c", &elem);
        } while ((elem<'0' || elem>'9') && elem != '*' && elem != '+' && elem != '.' && elem != '/' && elem != '-');
        if (elem != '.')
            poneC(C, elem);
    } while (elem != '.' && !vaciaC(*C));
}

void resultadoOperacion(TCola *C){
    TPila PAux;
    TElementoP elemP, elemPAux;
    TElementoC elemC, operacion;
    int error = 0, res = 0;
    iniciaP(&PAux);

    while (!vaciaC(*C) && error == 0){
        sacaC(C, &elemC);
        if (elemC >= '0' && elemC <='9'){
            elemP = elemC-48;
            poneP(&PAux, elemP);
        } else {
            operacion = elemC;
            sacaP(&PAux, &elemP);
            sacaP(&PAux, &elemPAux);

            if(operacion == '*')
                elemP = elemP*elemPAux;
            else if(operacion == '/'){
                if (elemPAux != 0)
                    elemP = elemP / elemPAux;
                else
                    error = 1;
            }else if(operacion == '+')
                elemP = elemP + elemPAux;
            else if(operacion == '-')
                elemP = elemP-elemPAux;
        
            if (error == 0)
                poneP(&PAux, elemP);
        }
    }
    sacaP(&PAux, &elemP);
    printf("La respuesta a la operacion es: %d\n", elemP);
}