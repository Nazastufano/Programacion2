#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 9. A partir de una lista circular no ordenada con los DNI (cadena de 8), sexo (carácter F-M), emitió 
voto? (S-N)  de los votantes en el padrón de una mesa, resolver mediante una función para 
cada item: 
a) listar los votantes femeninos que han emitido el voto 
b) contar los votantes de cada sexo (hayan o no votado). 
c) buscar un DNI, que es dato, en la lista de votantes y mostrar si votó o no. 
d) eliminar los votantes que no han emitido el voto y almacenar sus DNI en un archivo binario 
(almacenando DNI y sexo). */

typedef struct nodoC{
    char DNI[9];
    char sexo, haVotado;
    struct nodoC * sig;
}nodoC;

typedef nodoC * TListaC;

typedef struct {
    char DNI[9];
    char sexo;
}TElementoAB;

void listarVotantesF(TListaC LC);
void contarVotantesPS(TListaC LC);
void buscarPorDNI(TListaC LC, char DNI[9]);
void eliminarNoVotantes(TListaC *LC, char nomArch[20]);

void main(){
    TListaC LC;
    char DNI[9];

    LC = NULL;
    //cargaL(&LC);
    listarVotantesF(LC);

    contarVotantesPS(LC);
    
    printf("Ingrese el DNI de una persona para buscar: \n");
    scanf("%s", DNI);
    buscarPorDNI(LC, DNI);

    eliminarNoVotantes(&LC, "noVoto.dat");
}

void listarVotantesF(TListaC LC){
    TListaC aux;
    if (LC != NULL){
        aux = LC->sig;

        do{
            if (aux->sexo == 'F' && aux->haVotado == 'S')
                printf("El votante femenino de DNI: %s ha votado \n", aux->DNI);
            
            aux = aux->sig;
        }while (aux != LC);
    }
}

void contarVotantesPS(TListaC LC){
    TListaC aux;
    int contF = 0, contM = 0;
    if (LC != NULL){
        aux = LC->sig;
        do{
            if (aux->sexo == 'F')
                contF++;
            else
                contM++;
            aux = aux->sig;
        }while (aux != LC);
        printf("La cantidad de votantes femeninos es: %d, y de masculinos %d\n", contF, contM);
    }

}

void buscarPorDNI(TListaC LC, char DNI[9]){
    TListaC aux;
    if (LC != NULL){
        aux = LC->sig;
        while (aux != LC && strcmp(DNI, aux->DNI) != 0)
            aux = aux->sig;
        
        if (strcmp(DNI, aux->DNI) == 0){
            printf("El votante de DNI: %s", DNI);
            if (aux->haVotado == 'N')
                printf("no ");
            printf("ha emetido voto \n");
        }
    }
}

void eliminarNoVotantes(TListaC *LC, char nomArch[20]){
    TListaC act, ant = NULL, elim;
    TElementoAB elem;
    FILE* archB;

    if (*LC != NULL){
        if ((archB = fopen(nomArch, "wb")) == NULL)
            printf("El archivo binario no se pudo abrir. Es posible que no exista. \n");
        else {
            act = (*LC)->sig;
            ant = *LC;
            do{
                if (act->haVotado == 'N'){
                    elim = act;
                    
                    strcpy(elem.DNI, elim->DNI);
                    elem.sexo = elim->sexo;
                    fwrite(&elem,sizeof(TElementoAB), 1, archB);

                    act = act->sig;
                    ant->sig = act;
                    if (elim == *LC)
                        if (*LC == (*LC)->sig)
                            *LC = NULL;
                        else
                            *LC = ant;
                    free(elim);
                } else {
                    ant = act;
                    act = act->sig;
                }
            } while (act != *LC && *LC != NULL);
            fclose(archB);
        }
    }
}