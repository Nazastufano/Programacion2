
/* 16. Calcular el camino más corto entre todos los pares de vértices, para el digrafo representado por
la siguiente matriz de adyacencia, aplicando:
    a) el algoritmo de Dijkstra
    b) el algoritmo de Floyd 

        0  30 0  13
        22 0  10 12
        0  25 0  0
        13 6  0  0
        
Además, en ambos casos determinar cómo se conforma el camino mínimo 

a)Algoritmo de Dijkstra

S = {1}
D = [0, 30, ∞, 13]
               x
P = [0, 0, ∞, 0]


S = {1, 4}
D[2] = min(30, 13+6) = 19

D = [0, 19, ∞, 13]
        x
P = [0, 4, ∞, 0]


S = {1, 4, 2}
D[3] = min(∞, 19+10) = 29

D = [0, 19, 29, 13]
            x
P = [0, 4, 2, 0]


S = {1, 4, 2, 3}

D = [0, 19, 29, 13]
P = [0, 4, 2, 0]


El camino mínimo se conforma como:

1-->4-->2-->3
 13  6   10 



b) Algoritmo de Floyd 

        0  30 ∞  13       0 0 ∞ 0
  A0 =  22 0  10 12   P = 0 0 0 0
        ∞  25 0  ∞        ∞ 0 0 ∞
        13 6  ∞  0        0 0 ∞ 0

k = 1
No reviso los casos donde k=i ^ k=j
        -----------
  A0 =  |  \  10 12
        |  25 \  ∞
        |  6  ∞  \

A[2,3] = min(A[2,3], A[2,1] + A[1,3]) = min(10, 22+∞) = 10
A[2,4] = min(A[2,4], A[2,1] + A[1,4]) = min(12, 22+13) = 12
A[3,2] = min(A[3,2], A[3,1] + A[1,2]) = min(25, ∞+30) = 25
A[3,4] = min(A[3,4], A[3,1] + A[1,4]) = min(∞, ∞+13) = ∞
A[4,2] = min(A[4,2], A[4,1] + A[1,2]) = min(6, 13+30) = 6
A[4,3] = min(A[4,3], A[4,1] + A[1,3]) = min(∞, 13+∞) = ∞


        0  30 ∞  13         0 0 ∞ 0
  A1 =  22 0  10 12   P1 =  0 0 0 0
        ∞  25 0  ∞          ∞ 0 0 ∞
        13 6  ∞  0          0 0 ∞ 0


k = 2

No reviso los casos donde k=i ^ k=j
        \  |  ∞  13
  A1 =  -- \ ------
        ∞  |  \  ∞ 
        13 |  ∞  \

A[1,3] = min(A[1,3], A[1,2] + A[2,3]) = min(∞, 30+10) = 40 x
A[1,4] = min(A[1,4], A[1,2] + A[2,4]) = min(13, 30+12) = 13
A[3,1] = min(A[3,1], A[3,2] + A[2,1]) = min(∞, 25+22) = 47 x
A[3,4] = min(A[3,4], A[3,2] + A[2,4]) = min(∞, 25+12) = 37 x
A[4,1] = min(A[4,1], A[4,2] + A[2,1]) = min(13, 6+22) = 13
A[4,3] = min(A[4,3], A[4,2] + A[2,3]) = min(∞, 6+10) = 16 x


        0  30 40 13         0 0 2 0
  A2 =  22 0  10 12   P2 =  0 0 0 0
        47 25 0  37         2 0 0 2
        13 6  16 0          0 0 2 0

k = 3

No reviso los casos donde k=i ^ k=j

        \  30  | 13
  A2 =  22 \   | 12
        -- -- \  -- 
        13 6   | \  

A[1,2] = min(A[1,2], A[1,3] + A[3,2]) = min(30, 40+25) = 30
A[1,4] = min(A[1,4], A[1,3] + A[3,4]) = min(13, 40+37) = 13
A[2,1] = min(A[2,1], A[2,3] + A[3,1]) = min(22, 10+47) = 22
A[2,4] = min(A[2,4], A[2,3] + A[3,4]) = min(12, 10+37) = 12
A[4,1] = min(A[4,1], A[4,3] + A[3,1]) = min(13, 16+47) = 13
A[4,2] = min(A[4,2], A[4,3] + A[3,2]) = min(6, 16+25) = 6


        0  30 40 13         0 0 2 0
  A3 =  22 0  10 12   P3 =  0 0 0 0
        47 25 0  37         2 0 0 2
        13 6  16 0          0 0 2 0

k = 4

No reviso los casos donde k=i ^ k=j

        \  30 40 |
  A3 =  22 \  10 |
        47 25 \  |
        -- -- -- \ 

A[1,2] = min(A[1,2], A[1,4] + A[4,2]) = min(30, 13+6) = 19 x
A[1,3] = min(A[1,3], A[1,4] + A[4,3]) = min(40, 13+16) = 29 x
A[2,1] = min(A[2,1], A[2,4] + A[4,1]) = min(22, 12+13) = 22
A[2,3] = min(A[2,3], A[2,4] + A[4,3]) = min(10, 12+16) = 10
A[3,1] = min(A[3,1], A[3,4] + A[4,1]) = min(47, 37+13) = 47
A[3,2] = min(A[3,2], A[3,4] + A[4,2]) = min(25, 37+6) = 25


        0  19 29 13         0 4 4 0
  A4 =  22 0  10 12   P4 =  0 0 0 0
        47 25 0  37         2 0 0 2
        13 6  16 0          0 0 2 0


*/