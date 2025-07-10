
/* 13. Para el grafo del ejercicio 10:
a) encontrar el árbol abarcador de costo mínimo (AAM) mediante el algoritmo de Prim
b) encontrar el árbol abarcador de costo mínimo (AAM) mediante el algoritmo de Kruskal 


        1
    1-------3       6
    |     / | \3  /1
   3|  2/  1|   5
    | /     | /2  \4
    2-------4       7
        4

a) AMM con Prim

Algoritmo de Prim
    Se inicia un conjunto U con un vértice cualquiera de V. Se consideran las aristas que conectan un
vértice de U con un vértice de V-U, de ellas se elige la de menor costo.
    Paso 1: Asignar a un conjunto U de vértices un vértice cualquiera, a partir de él se construirá el AAM
    Paso 2: localizar la arista (u,v) con menor costo que conecta un vértice de U con un vértice de V-U,
agregar v a U y la arista al árbol abarcador
    El proceso termina cuando U=V 

    1

U = {3}
(1,3):1 x 
(1,2):3

        1
    1-------3

U = {3, 1}
(1,2):3
(2,3):2
(3,4):1 x
(3,5):3


        1
    1-------3
            |
           1|
            |
            4

U = {3, 1, 4}
(1,2):3
(2,3):2 
(3,5):3
(4,5):2 x
(4,2):4


        1
    1-------3
            |
           1|   5
            | /2
            4

U = {3, 1, 4, 5}
(1,2):3
(2,3):2 
(4,2):4
(5,6):1 x
(5,7):4


        1
    1-------3       6
            |     /1
           1|   5
            | /2
            4

U = {3, 1, 4, 5, 6}
(1,2):3
(2,3):2 x
(4,2):4
(5,7):4

        1
    1-------3       6
          / |     /1
       2/  1|   5
      /     | /2
    2       4


U = {3, 1, 4, 5, 6, 2}
(5,7):4 x


        1
    1-------3       6
          / |     /1
       2/  1|   5
      /     | /2  \4
    2       4       7

U = {3, 1, 4, 5, 6, 2, 7}



        1
    1-------3       6
    |     / | \3  /1
   3|  2/  1|   5
    | /     | /2  \4
    2-------4       7
        4



b) AMM con Kruskal

Algoritmo de Kruskal
    Se considera la inclusión de las aristas en orden creciente por costo. Una arista se incluye sólo si no
forma ciclo (un ciclo implicaría dos caminos entre un mismo par de vértices).
    Paso 1: Generar un grafo T=(V,∅) constituido por todos los vértices de V y ninguna arista.
    Paso 2: Para construir componentes conexas cada vez más grandes, se examinan las aristas de E en
orden creciente de costo. Se agrega la arista si conecta dos vértices que se encuentran en componentes
conexas distintas; en caso contrario, se descarta la arista.
    Cuando todos los vértices están en una misma componente conexa, T será el AAM


T = (V, ∅)
    1       3       6
                    
                5
                    
    2       4       7
Aristas disponibles:
(1,3):1 
(3,4):1
(5,6):1
(4,5):2
(2,3):2
(1,2):3
(3,5):3
(2,4):4
(5,7):4

T
        1
    1-------3       6
                    
                5
                    
    2       4       7

Aristas disponibles:
(1,3):1 x 
(3,4):1
(5,6):1
(4,5):2
(2,3):2
(1,2):3
(3,5):3
(2,4):4
(5,7):4

T
        1
    1-------3       6
            |       
           1|   5
            |       
    2       4       7

Aristas disponibles:
(3,4):1 x
(5,6):1
(4,5):2
(2,3):2
(1,2):3
(3,5):3
(2,4):4
(5,7):4

T
        1
    1-------3       6
            |     /1
           1|   5
            |       
    2       4       7

Aristas disponibles:
(5,6):1 x
(4,5):2
(2,3):2
(1,2):3
(3,5):3
(2,4):4
(5,7):4

T
        1
    1-------3       6
            |     /1
           1|   5
            | /2    
    2       4       7

Aristas disponibles:
(4,5):2 x
(2,3):2
(1,2):3
(3,5):3 descartada por bucle
(2,4):4
(5,7):4

T
        1
    1-------3       6
          / |     /1
       2/  1|   5
      /     | /2    
    2       4       7

Aristas disponibles:
(2,3):2 x
(1,2):3 descartada por bucle
(2,4):4 descartada por bucle
(5,7):4

T
        1
    1-------3       6
          / |     /1
       2/  1|   5
      /     | /2  \4 
    2       4       7

Aristas disponibles:
(5,7):4 x

T
        1
    1-------3       6
          / |     /1
       2/  1|   5
      /     | /2  \4 
    2       4       7
*/