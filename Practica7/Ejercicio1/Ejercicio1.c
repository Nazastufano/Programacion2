
/* 1. Dado el siguiente árbol:

        5
      /   \
     8     4
    / \   /
   3   6 1
           \
            2

a) Mostrar (sin desarrollar un programa):
    1. el contenido de sus nodos según cada recorrido: preorden, inorden, postorden.
    2. el contenido del nodo raíz, y para cada nodo indicar: grado, nivel, valor del padre y
    del hermano.
b) Responder: ¿cuál es la profundidad del árbol? 


a) 
1. preorden: 5, 8, 3, 6, 4, 1, 2
   inorden: 3, 8, 6, 5, 2, 1, 4
   postorden: 3, 6, 8, 2, 1, 4, 5

2. contenido de nodo raiz: 5
   
    | nodo | grado | nivel | valor del padre | valor del hermano |
    |  5   |   2   |   0   |     no tiene    |      no tiene     |
    |  8   |   2   |   1   |        5        |         4         |
    |  4   |   1   |   1   |        5        |         8         |
    |  3   |   0   |   2   |        8        |         6         |
    |  6   |   0   |   2   |        8        |         3         |
    |  1   |   1   |   2   |        4        |      no tiene     |
    |  2   |   0   |   3   |        1        |      no tiene     |

b) la profundidad del arbol es 3
*/