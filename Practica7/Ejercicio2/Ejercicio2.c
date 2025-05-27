
/* 2. A partir de las siguientes expresiones aritméticas:
    • 5 + 8 * 3 – 6 *3
    • 6 * (5 + 2) / (6 - 2)

a) Diagramar el árbol correspondiente, teniendo en cuenta precedencia de operadores y
paréntesis (el recorrido inorden del árbol debe representar a la expresión).

b) A partir del árbol, y sin desarrollar un programa, recorrerlo en postorden mostrando su
contenido, para verificar que representa la notación polaca inversa. 

2. 
a)
• 5 + 8 * 3 – 6 *3
        -
      /   \
     +     *
   /   \   / \
  5    *  6   3
      / \
     8   3

• 6 * (5 + 2) / (6 - 2)

        /
      /   \
     *     -
    / \   / \
   6  +  6   2
     / \
    5   2

b) postorden: 5 8 3 * + 6 3 * - 
   postorden: 6 5 2 + * 6 2 - /



*/