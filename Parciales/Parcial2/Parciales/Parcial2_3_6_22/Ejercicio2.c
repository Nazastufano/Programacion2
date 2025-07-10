
/* Ej 2- (Utilizar TDA N-ario) Dado un árbol N-Ario de caracteres verificar que exista algún nodo no
hoja de grado par cuya clave sea vocal y todos sus hijos también lo son.
    Mostrar la invocación de la solución desarrollada */

int existe(ARBOL A, pos P){
    pos C;
    int grado = 0, pEsVocal, condicion = 1, cu = 0, esHoja = 1;

    if (!nulo(P)){
        C = hijoMasIzq(P,A);
        
        if (!nulo(hijoMasIzq(C,A))){
            grado = calcGrado(A,P);
            pEsVocal = esVocal(info(P,A));
            esHoja = 0;
        } 

        while (!nulo(C) && !cu){
            if (grado % 2 == 0 && pEsVocal && !esHoja)
                condicion = condicion && esVocal(info(C,A));    
            else
                condicion = 0;
                
            cu = cu || existe(A,C);
            
            C = hermanoDer(C,A);
        }

        if (condicion)
            return 1;   
    }
    return 0;
}

int calcGrado(ARBOL A, pos P){
    pos C;  
    int grado = 0;
    if (!nulo(P)){
        C = hijoMasIzq(P,A);
        while (!nulo(C)){
            grado++;
            C = hermanoDer(C,A);
        }
    }
    return grado;
}