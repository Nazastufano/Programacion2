#include <stdio.h>

/* 22. Responder:
a) ¿Por qué no es correcta la siguiente sentencia: scanf(“%s”, &cad)?
b) ¿Qué instrucción resulta conveniente para leer por teclado apellido y nombre de una
persona: gets o scanf? Justificar la elección.
c) ¿Qué representan los valores devueltos por la función strcmp? 

a) Es incorrecta ya que una cadena de caracteres es un arreglo de caracteres terminado en el carácter nulo (\0).
b) Resulta conveniente usar gets, ya que scanf detecta el espacio como separacion de palabras
mientras que el gets, espera al Enter para transformarlo en el caracter nulo '\0' y terminar la palabra.
c) 0 → Las cadenas son iguales (strcmp(cad1, cad2) == 0).
< 0 → cad1 es menor que cad2 (alfabéticamente antes).
> 0 → cad1 es mayor que cad2 (alfabéticamente después).


*/
