/* 4. Completar el resultado que muestran los siguientes programas:
a) #include <stdio.h>
int main(){
    int a, b, c = 3, d = 2;
    a = 8 - 5 * 3 + 2;
    b = 7 % 3 + 4 * 2;
    printf(" valor de a %d\tvalor de b %d\n", a ,b); __________________1)
    b %= a;
    printf(" valor de b %d\t\n", b); __________________2)
    b =(-4) % 3;
    printf(" valor de b %d\t\n", b); __________________3)
    if(d = a)
        printf(" d y a son iguales ");
    else printf(" d y a son distintos ");
    
    return 0; __________________4)
} 

b) #include <stdio.h>
int main(){
    int c=3, d=2;
    c -= d++ * 3;
    printf(" valor de c %d\tvalor de d %d\n", c, d); _________________1)
    return 0;
} 

c) #include <stdio.h>
int main() {
    int c = 3, l;
    c = (c * 2 - (l = 4, -- l));
    printf(" valor de c %d\t valor de l %d\n", c, l); ______________1)
    getch(); ----> observacion personal, falta declarar la libreria <conio.h>
    return 0;
}

a.1) valor de a -5    valor de b 9

a.2) valor de b 4    

a.3) valor de b 2    

a.4) d y a son iguales 

b.1) valor de c -3    valor de d 3

c.1) valor de c 3     valor de l 3
*/