/* Ej 1.- lndicar V o F, justificando o ejemplificando adecuadamente (de lo contrario tendra puntaje cero) 
a) Un arbol AVL es un arbol binario en el cual se verifica que la longitud de todas sus ramas es la 
misma o difieren en, a la sumo, 1. 
b) No podria implementarse una pila en memoria estatica iniciando el tope en un valor coincidente 
con el tamaño del arreglo. 

a) Verdadero porque un arbol es AVL cuando el factor de equilibro de cada nodo varia entre -1 y 1
Si la diferecia de longitud entre ramas es mayor a 1 o menor a -1 ese nodo no estaria balanceado
por lo tanto no es AVL.

b)Falso, si es posible. Cambiarian todas las funciones de TDA. Para agregar un dato a la pila 
se deberia restar 1 en tope como limite 0. Para sacar datos de la pila se deberia sumar y siendo el tope
coincidente con el tamaño del arreglo.
*/