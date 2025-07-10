
/* Ej 4- Dadas las matrices A0 y A2 generadas al aplicar parcialmente Floyd en un digrafo con
vértices numerados de 1 a 4, se pide a) graficar el digrafo original y b) completar la
ejecución del algoritmo desde A2 para hallar la matriz final.

(& = INF)

     0 5  & 25       0 5  & 9
A0 = & 0  & 4   A2 = & 0  & 4
     7 13 0 &        7 12 0 16
     & &  8 0        & &  8 0



        5
a)  1------>2
    ^ \ 13^ |
   7|   \25 |4
    | /   v v
    3<------4

b) 
Busco si existen caminos de vi a vj que pasando por un vertice vk y que la suma de sus arista c'' < c + c' 

     0 5  & 9
A2 = & 0  & 4
     7 12 0 16
     & &  8 0

no revisas los k = i ^ k = j
     \ 5  | 9
A2 = & \  | 4
     - - \  -
     & &  | \

A[1,2] = min(A[1,2], A[1,3] + A[3,2]) = min(5, & + 12) = 5
A[1,4] = min(A[1,4], A[1,3] + A[3,4]) = min(9, &+16) = 9
A[2,1] = min(A[2,1], A[2,3] + A[3,1]) = min(&, &+7) = &
A[2,4] = min(A[2,4], A[2,3] + A[3,4]) = min(4, &+4)= 4
A[4,1] = min(A[4,1], A[4,3] + A[3,1]) = min(&, 8+7) = 15 x
A[4,2] = min(A[4,2], A[4,3] + A[3,2]) = min(&, 8+12) = 20 x

     0  5  & 9
A3 = &  0  & 4
     7  12 0 16
     15 20 8 0

Vuelvo a verificar si existen caminos mas cortos con k=4

no reviso los k=i ^ k=j

     \  5  & |
A3 = &  \  & |
     7  12 \ |
     -- -- - \

A[1,2] = min(A[1,2], A[1,4] + A[4,2]) = min(5, 9+20) = 5
A[1,3] = min(A[1,3], A[1,4] + A[4,3]) = min(&, 9+8) = 15 x
A[2,1] = min(A[2,1], A[2,4] + A[4,1]) = min(&, 4+15) = 20 x
A[2,3] = min(A[2,3], A[2,4] + A[4,3]) = min(&, 4+8) = 12 x
A[3,1] = min(A[3,1], A[3,4] + A[4,1]) = min(7, 16+15) = 7
A[3,2] = min(A[3,2], A[3,4] + A[4,2]) = min(12, 16+20) = 12


     0  5  15 9
A4 = 20 0  12 4
     7  12 0  16
     15 20 8  0

*/

