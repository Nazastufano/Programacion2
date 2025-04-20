#include <stdio.h>
#include "funciones.h"
/* 10. Ingresar una secuencia de caracteres terminada en punto que representa una expresión
aritmética.
    a. Comprobar que los paréntesis estén balanceados, de no ser así informar si falta
    izquierdo o derecho. Los paréntesis son los únicos símbolos a controlar.
    b. Agregar a la expresión la presencia y comprobación de corchetes y llaves. */

void comprobarParentesis(TCola *);
void cargarCola(TCola *);
void mostrarCola(TCola *);
void comprobarPCL(TCola *);
void contarParentesis(int [6], TElementoC);
int verificarParentesis(int [6], int);
void main(){
    TCola C;

    iniciaC(&C);

    cargarCola(&C);

    //mostrarCola(&C);

    //comprobarParentesis(&C);
    comprobarPCL(&C);
}

void cargarCola(TCola *C){
    TElementoC elem;
    
    do{
        printf("Ingrese elemento ( . = terminar)\n");
        scanf(" %c", &elem);
        if (elem != '.')
            poneC(C,elem);
    } while (elem != '.');
}

void mostrarCola(TCola *C){
    TElementoC elem;

    while (!vaciaC(*C)){
        sacaC(C, &elem);
        printf("%c", elem);
    }
    printf("\n");
}

void comprobarParentesis(TCola *C){
    int primero = 0, segundo = 0;
    TElementoC elem;
    while (!vaciaC(*C) && segundo == 0){
        sacaC(C, &elem);
        if (elem == '(')
            primero = 1;
        else if (elem == ')')
            segundo = 1;
    }

    if (primero == 1)
        if (segundo == 1)
            printf("Los parentesis estan balanceados \n");
        else
            printf("Falta el segundo parentesis \n");
    else 
        printf("Falta el primer parentesis \n");
}

void comprobarPCL(TCola *C){
    int cont[6] = {0};
    TElementoC elem, elemEncontrado = '.';
    while (!vaciaC(*C)){
        sacaC(C, &elem);
        contarParentesis(cont, elem);
    }

    if (verificarParentesis(cont, 0) == -1)
        printf("No hubo parentesis\n");
    else if (verificarParentesis(cont, 0))
        printf("Los parentesis estan balanceados\n");
    else if (cont[0]>cont[1])
        printf("Falta el segundo parentesis \n");
    else
        printf("Falta el primer parentesis \n");
    
    if (verificarParentesis(cont, 2) == -1)
        printf("No hubo cochetes\n");
    else if (verificarParentesis(cont, 2))
        printf("Los corchetes estan balanceados\n");
    else if (cont[2]>cont[3])
        printf("Falta el segundo corchete \n");
    else
        printf("Falta el primer corchete \n");
    
    if (verificarParentesis(cont, 4) == -1)
        printf("No hubo llaves\n");
    else if (verificarParentesis(cont, 4))
        printf("Las llaves estan balanceadas\n");
    else if (cont[4]>cont[5])
        printf("Falta la segunda llave \n");
    else
        printf("Falta la primer llave \n");
}

void contarParentesis(int cont[6], TElementoC elem){
    switch (elem){
    case '(':
        cont[0] +=1;
        break;
    case ')':
        cont[1] +=1;
        break;
    case '[':
        cont[2] +=1;
        break;
    case ']':
        cont[3] +=1;
        break;
    case '{':
        cont[4] +=1;
        break;
    case '}':
        cont[5] +=1;
        break;
    default:
        break;
    }
}

int verificarParentesis(int cont[6], int i){
    if (cont[i] == 0 && cont[i+1] == 0)
        return -1;
    else
        return cont[i] == cont[i+1];
}