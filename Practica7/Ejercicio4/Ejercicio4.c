
/* 4. Corregir los errores en la siguiente función void, la cual genera un arreglo de caracteres con los
nodos de grado 2 de un árbol binario.

void arrgrado2(arbol a, char v[N], int dimv) {
    if (a != NULL) {
        if(a->izq != NULL && a->der == NULL) { // grado 2
            (*dimv)++;
            v[dimv] = a->dato;
        } else 
            arrgrado2(a->izq, v[], dimv);
            arrgrado2(a->der, v[], dimv);
    }
} 
    
void arrgrado2(arbol a, char v[N], int dimv) {//dimv no es parametro de salida
    if (a != NULL) {
        if(a->izq != NULL && a->der == NULL) { // grado 2 //tanto izq como der tiene que ser != NULL
            (*dimv)++;
            v[dimv] = a->dato; // debe ser v[*dimv]
        } else //no termina de recorrer el arbol
            arrgrado2(a->izq, v[], dimv); //el vector se pasa como v, no como v[]
            arrgrado2(a->der, v[], dimv); //se ejecuta siempre y la linea de arriba se ejecuta solamente cuando no se cumple la condicion del if
    }
} 

*/

void arrgrado2(arbol a, char v[N], int *dimv) {
    if (a != NULL) {
        if(a->izq != NULL && a->der != NULL) { // grado 2 
            (*dimv)++;
            v[*dimv] = a->dato;
        }
        
        arrgrado2(a->izq, v, dimv);
        arrgrado2(a->der, v, dimv);
    }
} 