
/* 18. Transformar gráficamente el siguiente bosque en un árbol binario:

    A    B          L
        / \        / \
       C   D      M   N
         / /\ \      /
        E F  G H    O
         /|\
        I J K




  A------B----------L
        / \        / \
       C___D      M___N
         / /\ \      /
        E_F__G__H    O
         /|\
        I_J_K

0) uno los nodos raiz
1) uno los nodos hermanos
2) quedarme con el primer hijo izq
3) conectar dichos hermanos como una sucecion de nodos hijo a derecha

         A
          \
           B
         /   \
        C     L
         \   /
          D  M
         /    \
        E      N
         \    /
          F  O
         / \
        I   G
         \    \
          J    H
           \
            K

*/