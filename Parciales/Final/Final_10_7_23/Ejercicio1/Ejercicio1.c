/* Ej 1.- Indicar V o F, justificando o ejemplificando adecuadamente (de lo contrario tendrá puntaje cero)
a) Las rotaciones en un árbol AVL desbalanceado, se determinan siguiendo dos niveles desde el nodo
desbalanceado considerando el signo del factor de equilibrio.
b) Si se aplica el recorrido en amplitud sobre un digrafo conexo, es posible asegurar que la pila nunca
va a vaciarse. 


b) Falso, es posible asegurar que la cola nunca va a vaciarse si el grafo es conexo. 
el recorrido por amplitud no trabaja con pilas.

Si se aplica el recorrido de amplitud en un digrafo, puede ser que al recorrer te quedes
sin opciones adyacentes se vacie la cola y aun asi se encuentren vertices sin visitar
y siendo conexos al grafo

Conclusion: El recorrido de amplitud se aplica a grafos y se usa la estructura Cola.
*/

