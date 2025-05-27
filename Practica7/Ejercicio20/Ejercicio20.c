#include <stdio.h>

/* 20. Dado un árbol binario proveniente de la conversión de un árbol general:
a) hallar la cantidad de nodos que habia en niveles impares.
b) obtener el promedio de las claves cuyo grado era K (dato de entrada).
c) obtener la altura del árbol original
d) determinar el grado del árbol original. */


typedef struct nodo{ 
    int dato;
    struct nodo *izq, *der;
}nodo;

typedef nodo * ARBOL;

int cantNodosEnNivImp(ARBOL A, int nivel);
void promClavesGradK(ARBOL A, int izq, int ant, int K, int *suma, int *cantN);
int contarHijos(ARBOL A);
void obtenerAltura(ARBOL A, int nivel, int *profundidad);
void gradoArbolOriginal(ARBOL A, int *grado, int izq);

void main(){
    ARBOL A;
    int suma = 0, K, cantN = 0, profundidad = 0, grado = 0;
    A = NULL;
    //cargaA(&A);

    printf("La cantidad de nodos que habia en posiciones impares es: %d\n", cantNodosEnNivImp(A, 1));
    
    printf("Ingrese un grado para sumar las claves que tengan dicho grado: \n");
    scanf("%d", &K);
    promClavesGradK(A, 0, 0, K, &suma, &cantN);
    printf("El promedio de las claves de grado K=%d es: %.2f\n", K, (float)suma/cantN);

    obtenerAltura(A, 1, &profundidad);
    printf("La profundidad del arbol original es: %d\n", profundidad);

    gradoArbolOriginal(A, &grado,0);
    printf("El grado del arbol original es %d \n", grado);
}   


int cantNodosEnNivImp(ARBOL A, int nivel){
    int cont = 0;
    if (A != NULL){
        if (nivel % 2 != 0)
            cont = 1;
        return cont + cantNodosEnNivImp(A->izq, nivel + 1) + cantNodosEnNivImp(A->der, nivel);
    } else
        return 0;
}

void promClavesGradK(ARBOL A, int izq, int ant, int K, int *suma, int *cantN){
    if (A != NULL){
        if (izq == 1)
            if (contarHijos(A) == K){
                *suma += ant;
                *cantN += 1;
            }
        
        promClavesGradK(A->izq, 1, A->dato, K, suma, cantN);
        promClavesGradK(A->der, 0, ant, K, suma, cantN);
    }
}

int contarHijos(ARBOL A){
    int cont = 0;
    while (A != NULL){
        cont++;
        A = A->der;
    }
    return cont;
}

void obtenerAltura(ARBOL A, int nivel, int *profundidad){
    if (A != NULL){
        if (*profundidad < nivel)
            *profundidad = nivel-1;
        
        obtenerAltura(A->izq, nivel + 1, profundidad);
        obtenerAltura(A->der, nivel, profundidad);
    }
}

void gradoArbolOriginal(ARBOL A, int *grado, int izq){
    int cont;
    if (A != NULL){
        if (izq == 1){
            cont = contarHijos(A);
            if (cont > *grado)
                *grado = cont;
        }
        
        gradoArbolOriginal(A->izq, grado, 1);
        gradoArbolOriginal(A->der, grado, 0);
    }
}