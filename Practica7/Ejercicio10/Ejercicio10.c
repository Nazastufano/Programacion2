
/* 10. Corregir la siguiente función, la cual retorna si un valor recibido como parámetro se encuentra
en un ABB cuyas claves son enteros.

int busca(arbol a, int* x) {
    if (a != NULL)
        return 0;
    else
        if(x = a.dato)
            return 1;
        else
            if(x < a.dato)
                return busca(a.der, *x);
            else
                return busca(a->izq, *x); 
}

int busca(arbol a, int* x) { //manda un parametro de salida en una funcion int
    if (a != NULL) //siempre retorna 0. debe ser a == NULL
        return 0;
    else
        if(x = a.dato) //asigna a.dato a x. deberia ser x == a->dato
            return 1;
        else
            if(x < a.dato) //debe poner x > a->dat0
                return busca(a.der, *x); // debe ser a->der manda *x en vez de x
            else
                return busca(a->izq, *x); //manda *x en vez de x
}

*/

int busca(arbol a, int x){
    if (a != NULL)
        if(x == a.dato)
            return 1;
        else
            if(x > a.dato)
                return busca(a->der, x);
            else
                return busca(a->izq, x); 
    else
        return 0;
}