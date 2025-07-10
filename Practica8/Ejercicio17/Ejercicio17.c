
/* 17. Para un digrafo G(V,E) la Matriz de Alcance R de define como:
    {  1 si vk es alcanzable desde vi.
Rik {
    {  0 si vk no es alcanzable desde vi.
a) Determinar la dimensión de R
b) Construir R para el siguientes digrafo: 
    
    B------->D
    |    C       F
    |   ^  \    ^
    v /      v / 
    A------->E

a) la dimension de R es NxN con N = |V|

b)
        0 0 1 0 1 1
        1 0 1 1 1 1
    R = 0 0 0 0 1 1
        0 0 0 0 0 0
        0 0 0 0 0 1
        0 0 0 0 0 0

*/