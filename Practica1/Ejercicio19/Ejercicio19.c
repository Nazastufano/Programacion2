#include <stdio.h>
/* 19. Responder, siendo x un arreglo de 10 enteros (int x[10]):
a) ¿Se puede determinar por la siguiente invocación funarr(x, n) si x es parámetro de entrada o
de salida?

b) ¿Se puede acceder al contenido de x[10]? ¿Qué representa el valor obtenido? 

a) No se puede determinar si el arreglo es de entrada o de salida ya que En C, los arreglos se pasan por referencia 
de manera implícita, lo que significa que cualquier modificación dentro de funarr afectará el arreglo original.

b) Si bien los indices van de 0 a 9, se puede acceder especificamente a esa posicion.
Se va a encontrar con datos indefinidos, y no valores esperados. es un error semantico.
*/