#include "TDAArbol.h"
#include <stdio.h>
/* 23. Dado un árbol N-ario de enteros, desarrollar funciones utilizando TDA N.ARIO para:
    a) retornar la cantidad de nodos que posee.
    b) hallar el porcentaje de claves pares
    c) retornar su grado
    d) hallar la cantidad de nodos de grado impar que hay en niveles impares.
    e) verificar si cumple que para todas las claves salvo las de las hojas, su valor numérico es igual
    a la cantidad de hijos. (función int y función void)
    f) obtener el promedio de las claves del nivel K (dato) 
*/

int cantNodos(ARBOL A, pos P);
void porcentajeClavPar(ARBOL A, pos P, int *contP, int *contN);
int gradoArbol(ARBOL A, pos P);
int cantNodosGrImpNivImp(ARBOL A, pos P, int nivel);
int verificarInt(ARBOL A, pos P);
void verificarVoid(ARBOL A, pos P, int *condicion)
void promedioClavesNivK(ARBOL A, pos P, int K, int nivel, int *suma, int *cant);

void main(){
    ARBOL A;
    int contP = 0, contN = 0, condicion = 1, K, suma = 0, cant = 0;
    A = NULL;
    //cargarA(&A);
    printf("La cantidad de nodos es: %d\n",cantNodos(A, raiz(A)));
    porcentajeClavPar(A, raiz(A), &contP, &contN);
    printf("El porcentaje de claves pares es: %.2f \n", (float)contP*100/contN);

    printf("El grado del arbol es: %d\n", gradoArbol(A, raiz(A)));

    printf("La cantidad de nodos de grado impar en nivel impar es: %d\n", cantNodosGrImpNivImp(A,raiz(P),1));
    
    if (verificarInt(A, raiz(A)))
        printf("Todas las claves tienen el mismo valor numerico que su cantidad de hijos\n");
    else
        printf("No todas las claves tienen el mismo valor numerico que su cantidad de hijos\n");
    
    verificarVoid(A,raiz(A), &condicion);
    if (condicion)
        printf("Todas las claves tienen el mismo valor numerico que su cantidad de hijos\n");
    else
        printf("No todas las claves tienen el mismo valor numerico que su cantidad de hijos\n");
    
    printf("Ingrese un nivel para obtener el promedio de sus claves: \n");
    scanf("%d", &K);
    promedioClavesNivK(A,raiz(A),K,1,&suma,&cant);
    printf("El promedio de las claves de nivel K=%d, es: %.2f\n", (float)suma/cant);

}

//a) retornar la cantidad de nodos que posee.
int cantNodos(ARBOL A, pos P){
    pos C;
    int cont = 0;
    if (!nulo(P)){
        cont = 1;
        C = hijoMasIzq(A, P);
        while (!nulo(C)){
            cont += cantNodos(A, C);
            C = hermanoDer(C, A);
        }
    }
    return cont;
}


//b) hallar el porcentaje de claves pares

void porcentajeClavPar(ARBOL A, pos P, int *contP, int *contN){
    pos C;
    if (!nulo(P)){
        (*contP)++;
        if (info(P) % 2 == 0)
            (*contN)++;
        C = hijoMasIzq(P,A);
        while (!nulo(C)){
            porcentajeClavPar(A,C,contP,contN);
            C = hermanoDer(C,A);
        }
    }
}

// c) retornar su grado

int gradoArbol(ARBOL A, pos P){
    int maxGrado = 0, hijos = 0, subGrado;
    pos C;
    if (!nulo(P)){
        C = hijoMasIzq(P,A);
        while (!nulo(C)){
            hijos++;
            subGrado = gradoArbol(A,C);
            if (maxGrado < subGrado)
                maxGrado = subGrado;
            C = hermanoDer(C,A);
        }
    }
    return maxGrado > hijos ? maxGrado : hijos;
}

// d) hallar la cantidad de nodos de grado impar que hay en niveles impares.

int cantNodosGrImpNivImp(ARBOL A, pos P, int nivel){
    pos C;
    int hijos = 0, cont = 0;
    if (!nulo(P)){
        C = hijoMasIzq(P,A);
        while (!nulo(C)){
            hijos++;
            cont += cantNodosGrImpNivImp(A,C,nivel + 1);
            C = hermanoDer(C,A);
        }
    }
    return cont + (nivel % 2 && hijos % 2);
}


/* e) verificar si cumple que para todas las claves salvo las de las hojas, su valor numérico es igual
    a la cantidad de hijos. (función int y función void)*/

int verificarInt(ARBOL A, pos P){
    pos C;
    int hijos = 0, condicion = 1;
    if (!nulo(P)){
        C = hijoMasIzq(P,A);
        while (!nulo(C) && condicion){
            hijos++;
            condicion = verificarInt(A,C);
            C = hermanoDer(C,A);
        }
        if (!nulo(hijoMasIzq(P, A)) && condicion)
            condicion = info(P) == hijos;
    }
    return condicion;
}

void verificarVoid(ARBOL A, pos P, int *condicion){
    pos C;
    int hijos = 0;
    if (!nulo(P)){
        C = hijoMasIzq(P,A);
        while (!nulo(C) && *condicion){
            hijos++;
            verificarVoid(A,C, condicion);
            C = hermanoDer(C,A);
        }
        if (!nulo(hijoMasIzq(P,A)) && *condicion)
            *condicion = info(P) == hijos;
    }
}

//f) obtener el promedio de las claves del nivel K (dato)

void promedioClavesNivK(ARBOL A, pos P, int K, int nivel, int *suma, int *cant){
    pos C;
    if (!nulo(P)){
        if (K == nivel){
            (*suma) += info(P);
            (*cant)++;
        }
        
        C = hijoMasIzq(P,A);
        while (!nulo(C)){
            promedioClavesNivK(A, C, K, nivel + 1, suma, cant);

            C = hermanoDer(C,A);
        }
    }
}