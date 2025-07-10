

/* Ej 1- Dado un árbol binario de caracteres proveniente de la tranformación de un árbol 
general, hallar e informar la cantidad de elementos no vocales que había en cada uno de 
los primeros K niveles (dato) [considerar que K podria ser mayor a la profundidad del árbol] */

int contarEnNivel(ARBOL A,int izq, int nivel, int K){
    int cant = 0;
    if (A != NULL){
        if (nivel <= K){
            if (K == nivel && izq == 1)
                cant = calcElemNV(A);
            
            return cant + contarEnNivel(A->izq, 1, nivel+1, K) + contarEnNivel(A->der, 0, nivel, K);
        }
    }
    return 0;
}

int calcElemNV(ARBOL A){
    int cant = 0;
    while (A != NULL){
        if (!esVocal(A->dato))
            cant++;
        
        A = A->der;
    }
    return cant;
}

void mostrarNoVocalesPorNivel(ARBOL A, int K) {
    for (int i = 0; i < K; i++) {
        int cant = contarEnNivel(A, 1, 1, i);
        printf("Nivel %d: %d no vocales\n", i, cant);
    }
}