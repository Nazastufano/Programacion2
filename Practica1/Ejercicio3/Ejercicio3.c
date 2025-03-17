/* 3. Describir lo que imprimen los siguientes fragmentos de código (justificar si no imprimen nada):
a) char A;
A = 'a';
printf(" %c ", A); ______" a "______
printf(" %d ", A); ______" 97 "______
A = 'a' + 10;
printf(" %c ", A); ______" k "______
printf(" %d ", A); ______" 107 "______

b) int B;
B = 5;
printf(" %d ", B); ______" 5 "______
printf(" %c ", B); ______"  "______ Tratara de imprimir el caracter 5 de la tabla ascii que no es visible para la consola
B = 5 + 'A';
printf(" %d ", B); ______" 70 "______
printf(" %c ", B); ______" F "______

c) #define num 15
printf(" %d ", num); _____" 15 "_____
printf(" %c ", num); _____"  "_____ Tratara de imprimir el caracter 15 de la tabla ascii que no es visible para la consola

d) #define num 15
num = 5 + 'A';
printf(" %d ", num); _____"  "_____ Error, no se puede reasignar el valor de una constante
printf(" %c ", num); _____"  "_____ Error, no se puede reasignar el valor de una constante
*/