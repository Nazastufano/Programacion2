/* Ej 1.- Indicar V o F, justificando o ejemplificando adecuadamente (de lo contrario tendrá puntaje cero)
a) A partir de la matriz final An de Floyd sobre un digrafo G, se puede hallar la matriz de clausura
transitiva con solo un recorrido sobre An, sin necesidad de volver a acceder a la matriz de adyacencia de
G
b) Dado un grafo de N vértices, conexo, existen entre N y 2N posibles recorridos en amplitud. 


a) Verdero, ya que la matriz de clausura transitica toma el valor 1 si existe camino de un vertice
a otro, y 0 si no existe camino. Mientras que la matriz final An de Floyd toma valores != 0 si el camino no es
directo, 0 si el camino es directo y INF si no existe camino.
Con esto se puede saber que con un solo recorrido de la matriz An se puede armar la matriz CT ya que
tomaria como valor 1 en la posicion i,j si el valor de la misma es != INF, y 0 si es INF 

b) Falso
*/