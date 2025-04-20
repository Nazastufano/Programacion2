#include <stdio.h>
#include "funciones.h"

/* 11. Simular una fila de empleados para usar un horno microondas en el comedor de una empresa.
Para cada empleado se tiene: su número de legajo, el momento de arribo (en segundos a partir
de las 12:00) y la cantidad de segundos que piensa usar el horno. El programa debe mostrar
para cada empleado el tiempo en que empieza y termina el uso del horno. Al finalizar mostrar
tiempo promedio de espera y legajo con mayor tiempo de espera. */
void cargaCola(TCola *);
void convertirHoras(TElementoC, int);
void analisisFila(TCola *);
void main(){
    TCola C;
    
    iniciaC(&C);
    cargaCola(&C);

    analisisFila(&C);
}

void cargaCola(TCola *C){
    TElementoC elem;
    int cant, i, suma = 0;
    
    do{
        printf("Cuantos empleados desea ingresar? \n");
        scanf("%d", &cant);
    } while(cant<=0 || cant > MAX);

    for (i = 0; i < cant; i++){
        printf("Ingrese el legajo del empleado %d\n", i+1);
        scanf("%d", &elem.numLegajo);
        printf("Ingrese el momento de arribo del empleado %d\n", i+1);
        scanf("%d", &elem.momentoArribo);
        printf("Ingrese la cantidad de segundos de uso del horno %d\n", i+1);
        scanf("%d", &elem.cantSegUsoHorno);
        poneC(C,elem);
    }
}

void analisisFila(TCola *C){
    TElementoC elemAnt, elem;
    int sumaTiempoEspera = 0, legajoMayorEspera, mayorTiempoEspera = 0, tiempoEspera = 0;
    int cantEmpleadosEsp = 0;
    sacaC(C, &elemAnt);
    convertirHoras(elemAnt,tiempoEspera);
    while (!vaciaC(*C)){    
        sacaC(C,&elem);
        
        if (elemAnt.cantSegUsoHorno-elem.momentoArribo>=0){
            cantEmpleadosEsp++;
            tiempoEspera = (elemAnt.momentoArribo+elemAnt.cantSegUsoHorno)-elem.momentoArribo;
        } else
            tiempoEspera = 0;

        sumaTiempoEspera += tiempoEspera;
        
        convertirHoras(elem,tiempoEspera);

        if (mayorTiempoEspera < tiempoEspera){
            mayorTiempoEspera = tiempoEspera;
            legajoMayorEspera = elem.numLegajo;
        }
        elemAnt = elem;
    }        
    
    if (cantEmpleadosEsp){
        printf("El legajo del empleado que mas ha esperado es: %d\n",legajoMayorEspera);
        printf("El tiempo promedio de espera es: %.2f\n", (float)sumaTiempoEspera/cantEmpleadosEsp);
    } else {
        printf("Ningun empleado a esperado a usar el horno\n");
    }
}

void convertirHoras(TElementoC elem, int tiempoEspera){
    int hora, minutos;
    hora = (43200 + elem.momentoArribo) / 3600;
    minutos = ((elem.momentoArribo) / 60)%60;
    
    if (minutos>=10)
        printf("La hora de arribo es %d:%d\n", hora, minutos);
    else
        printf("La hora de arribo es %d:0%d\n", hora, minutos);

    
    hora = (43200 + elem.momentoArribo + elem.cantSegUsoHorno + tiempoEspera) / 3600;
    minutos = ((elem.momentoArribo + elem.cantSegUsoHorno + tiempoEspera) / 60) % 60;
    
    if (minutos>=10)
        printf("Y ha dejado el horno a las %d:%d \n", hora, minutos);
    else
        printf("Y ha dejado el horno a las %d:0%d \n", hora, minutos);
}