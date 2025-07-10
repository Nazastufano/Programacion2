
/* Ej 4- Dada la matriz de adyacencia de un dígrafo con vértices etiquetados de A a E, y los
vectores D y P generados al aplicar parcialmente Dijkstra en dicho dígrafo partiendo desde
A. Sabiendo que S ya contiene A y D (agregados en ese orden), se pide completar la
ejecución del algoritmo

        2  15 0 13 0
        0  0  4 2  7
MAdy =  14 0  0 3  2  D = [0 15 21 13 INF] P = [0 0 D 0 INF]
        9  33 8 0  0
        3  1  4 7  0

Hasta el momento se tiene
S = {A, D}
D = [0 15 21 13 INF]
P = [0 0 D 0 INF]
por lo que hay que buscar el nodo de menor costo que no pertenezca a S

En este caso: B
D = [0 15 21 13 INF] 
       x
S = {A, D, B}
Se calcula la distancia a los vertices no pertenecientes a S desde B
D[C] = min(21, 15+4) = 19
D[E] = min(INF, 15+7) = 22

D[0 15 19 13 22]
P[0 0  B  0  B]

Agregamos a S un vertice no visitado de coste minimo
En este caso C

S = {A, D, B, C}
D[E] = min(22, 19 + 2) = 21

D[0 15 19 13 21]
P[0 0  B  0  C]

Agregamos a S un vertice no visitado de costo minimo
En este caso E

S = {A, D, B, C, E}

Se termina el algoritmo al haber visitado todos los nodos





*/

