
/* 1. Sin desarrollar un programa, determinar en el siguiente digrafo:

B <-------  D  <------
|         ^  \^^      \ 
|       /     \\\      \
|     A       // \      E
|    ^  \    //   \    ^
v  /      v v/     \  /
C --------> F --- > G 

a) grados de entrada y salida de cada vértice.
b) todos los ciclos que pasan por el vértice C
c) todos los caminos del vértice A al E
d) todos los caminos del vértice B al D
e) todos los caminos de longitud 4 con origen en el vértice A
f) la matriz de adyacencia que lo representa.
g) la lista de adyacencia que lo representa.
h) la matriz de adyacencia que lo representa, suponiendo que no es un grafo dirigido. 



a) grados de entrada y salida de cada vértice.
V  Gre  Grs  
A   1    2
B   1    1
C   1    2
D   4    2
E   1    1
F   3    2
G   1    2

b) todos los ciclos que pasan por el vértice C
1) {C,A},{A,D},{D,B},{B,C}
2) {C,A},{A,F},{F,D},{D,B},{B,C}
3) {C,A},{A,F},{F,G},{G,D},{D,B},{B,C}
4) {C,A},{A,F},{F,G},{G,E},{E,D},{D,B},{B,C}
5) {C,F},{F,G},{G,E},{E,D},{D,B},{B,C}
7) {C,F},{F,G},{G,D},{D,B},{B,C}
8) {C,F},{F,D},{D,B},{B,C}
9) {C,F},{F,D},{D,F},{F,G},{G,E},{E,D},{D,B},{B,C}
10) {C,F},{F,D},{D,F},{F,G},{G,D},{D,B},{B,C}
11) {C,A},{A,F},{F,D},{D,F},{F,G},{G,E},{E,D},{D,B},{B,C}
12) {C,A},{A,F},{F,D},{D,F},{F,G},{G,D},{D,B},{B,C}
13) {C,A},{A,D},{D,F},{F,G},{G,D},{D,B},{B,C}
14) {C,A},{A,D},{D,F},{F,G},{G,E},{E,D},{D,B},{B,C}
15) {C,A},{A,D},{D,F},{F,D},{D,B},{B,C}

c) todos los caminos del vértice A al E
1) {A,F},{F,G},{G,E}
2) {A,F},{F,D},{D,B},{B,C},{C,F},{F,G},{G,E} 
3) {A,D},{D,F},{F,G},{G,E}
4) {A,D},{D,B},{B,C},{C,F},{F,G},{G,E}
5) {A,F},{F,D},{D,F},{F,G},{G,E}

d) todos los caminos del vértice B al D 
1) {B,C},{C,A},{A,D}
2) {B,C},{C,A},{A,F},{F,D}
3) {B,C},{C,A},{A,F},{F,G},{G,D}
4) {B,C},{C,A},{A,F},{F,G},{G,E},{E,D}
5) {B,C},{C,F},{F,D}
6) {B,C},{C,F},{F,G},{G,D}
7) {B,C},{C,F},{F,G},{G,E},{E,D}

e) todos los caminos de longitud 4 con origen en el vértice A 
1) {A,D},{D,B},{B,C},{C,A}
2) {A,D},{D,B},{B,C},{C,F}
3) {A,D},{D,F},{F,G},{G,E}
4) {A,D},{D,F},{F,G},{G,D}
5) {A,D},{D,F},{F,D},{D,B}
6) {A,F},{F,D},{D,B},{B,C}
7) {A,F},{F,D},{D,F},{F,G}
8) {A,F},{F,G},{G,D},{D,B}
9) {A,F},{F,G},{G,E},{E,D}


f) la matriz de adyacencia que lo representa. 

  A B C D E F G
A 0 0 0 1 0 1 0
B 0 0 1 0 0 0 0
C 1 0 0 0 0 1 0
D 0 1 0 0 0 1 0
E 0 0 0 1 0 0 0
F 0 0 0 1 0 0 1
G 0 0 0 1 1 0 0

g) la lista de adyacencia que lo representa. 

*/

