
/* Ej 2- (Utilizar TDA N-ario) Dado un árbol N-Ario de números naturales y un entero K
retornar mediante una función int, la cantidad de nodos en niveles menores a K que
verifican que su primer hijo es hoja y el resto de los hijos (si existen) son múltiplos del
primero. (K dato)
Si la solución es void, el puntaje obtenido será no mayor a 1.5p */


int existe(ARBOL A, pos P, int nivel, int K){
    pos C, H;
    int valorPriHij, cumple = 0;
    if (!nulo(P) && nivel<K-1){
        C = H = hijoMasIzq(P,A);
        nivel++;
        
        if (!nulo(C) && nulo(hijoMasIzq(H, A))){
            valorPriHij = info(H,A);
            if (nulo(hijoMasIzq(H, A))) {
                C = hermanoDer(C,A);

                while (!nulo(C) && valorPriHij % info(C,A) == 0)
                    C = hermanoDer(C,A);
                if (nulo(C))
                    cumple = 1;
            }
            while (!nulo(C)){
                cumple += existe(A, C, nivel, K);
                C = hermanoDer(C, A);
            }
        }
    }
    
    return cumple;
}


int existe(ARBOL A, pos P, int nivel, int K){
    pos C, H;
    int valorPriHij;
    if (!nulo(P) && nivel<K-1){
        C = H = hijoMasIzq(P,A);
        nivel++;
        if (!nulo(C)){
            if (nulo(hijoMasIzq(C,A))){
                valorPriHij = info(C,A);
                C = hermanoDer(C,A);
                while (!nulo(C) && valorPriHij % info(C,A) == 0)
                    C = hermanoDer(C,A);
                
                if (nulo(C))
                    return 1 + existe(A, hermanoDer(H,A), nivel, K);
                else
                    return existe(A, hermanoDer(H,A), nivel, K);
            } else
                return existe(A, C,nivel, K) + existe(A,hermanoDer(C,A),nivel,K);
        }
    }
    return 0;
}