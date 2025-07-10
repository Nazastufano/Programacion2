
/* Ej 2- (Utilizar TDA N-ario) Dado un árbol N-Ario de números naturales, retornar
mediante una función recursiva int la mayor clave de entre los nodos de grado G
(dato) ó 2G. En caso de que no exista ninguna, retornar -1.
    Desarrollar un main completo que incluya declaraciones, inicializaciones, invocaciones y
    resultados obtenidos.
    De resolverse mediante una función VOID, el puntaje obtenido no superará 1.5P */

int existe(ARBOL A, pos P, int G){
    pos C;
    int max = -1, valor, grado;
    if (!nulo(P)){
        C = hijoMasIzq(P,A);
        
        if (!nulo(C)){
            while (!nulo(C)){
                grado = cantGrado(A,C);
                if (grado == G || grado == 2*G)
                    if (max < info(C))
                        max = info(C);
                
                valor = existe(A,C,G);
                if (valor > max)
                    max = valor;
            
                C = hermanoDer(C,A);
            }
            return max;
        }    
    }
    return -1;
}

int cantGrado(ARBOL A, pos P){
    pos C;
    int grado=0;
    if (!nulo(P)){
        C = hijoMasIzq(P,A);
        while (!nulo(C)){
            grado++;
            C = hermanoDer(C,A);
        }
    }
    return grado;
}