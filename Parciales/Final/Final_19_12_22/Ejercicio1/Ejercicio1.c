
/* Ej 1.- Indicar V o F, justificando o ejemplificando adecuadamente (de lo contrario tendrá puntaje cero)
a) Al finalizar la ejecución del algoritmo de Floyd sobre un digrafo, si el mismo es no conexo en la diagonal habrá
posiciones con valor 0 y otras con valor infinito.
b) Al insertar una clave en un árbol AVL, se deben calcular los f.e. desde la raíz hasta la clave insertada (a la ida)
en el proceso de inserción.

a) Falso. Los valores de la diagonal principal en la matriz An final de Floyd van a ser 0
ya que esta matriz muestra el recorrido de peso minimo de un vertice a cualquier otro.
el peso de un vertice A a él mismo 0, ya que este es directo. entonces, aunque sea no conexo
el grafo, todo vertice camino directo a si mismo.

b) Falso. En la insercion de una clave en un arbol AVL, el calculo de los f.e debe ser desde la clave
insertada hasta la raiz, o sea, a la vuelta del preceso de inserción. 
*/