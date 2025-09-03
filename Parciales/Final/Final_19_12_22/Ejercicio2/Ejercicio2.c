#include <stdio.h>
#include <string.h>

/* Ej 2.- Una consultora de certificación de normas ISO maneja una lista circular con las normas (0..20) y las
empresas (0 a 39) que ha certificado (una empresa puede haber certificado una o más normas). Cada nodo de
esta lista contiene:
    Norma (ordenada, no se repite)
    NombreNorma (Cadena8)
    Sublista de empresas certificadas, en cada nodo:
        NúmeroEmpresa
        FechaCertificación (Cadena de formato aaaamm, ordenada por este campo)
Se pide:
a) Generar una matriz de 21x40 caracteres, tal que en la posición [i,j] contenga S o N según si la norma i fue
certificada o no por las empresa j. Hallar de forma recurisva mediante una función int la cantidad de empresas
que han certificado todas las normas.
b) Dados un mes MM (cadena) y una norma N, eliminar todas las empresas que hayan certificado N en el mes
MM. Si la norma quedara sin empresas certifacas, eliminarla también. A medida que se efectúa el proceso de
eliminación, generar un archivo binario ELIM.DAT de registros con la siguiente información para las empresas
eliminadas: NumeroEmpresa, Norma, FechaCertifiación */

#define NOR 21
#define EMP 40
#define ST8 9
#define ST6 7
#define ST2 3

typedef struct nodito{
    int numEmp;
    char fechaCert[ST6];
    struct nodito * sig;
}nodito;

typedef nodito * subLista;

typedef struct nodo{
    int norma;
    char nomNorma[ST8];
    subLista sub;
    struct nodo *sig;
}nodo;

typedef nodo * TListaC;

void generarMat(TListaC LC, char mat[NOR][EMP]);
void inicializarMat(char mat[NOR][EMP]);
int cantEmp(char mat[NOR][EMP], int i, int j);
void eliminar(TListaC *LC, char MM[ST2], int N, char nom[NOR]);

void main(){
    char mat[NOR][EMP], MM[ST2];
    TListaC LC;
    int N;
    cargaLC(&LC);

    generarMat(LC, mat);
    printf("La cantidad de empresas que han certificado todas las normas son: %d\n", cantEmp(mat, 0, 0));

    printf("Ingrese un mes \n");
    scanf("%s", MM);
    printf("Ingrese una norma \n");
    scanf("%d", &N);

    eliminar(&LC, MM, N, "ELIM.DAT");
}

void generarMat(TListaC LC, char mat[NOR][EMP]){
    TListaC act = LC->sig;
    subLista sAct;
    
    inicializarMat(mat);

    do{
        sAct =act->sub;
        
        while (sAct != NULL){
            mat[act->norma][sAct->numEmp] = 'S';

            sAct = sAct->sig;
        }
        act = LC->sig;
    } while (act != LC->sig);
}

void inicializarMat(char mat[NOR][EMP]){
    int i, j;
    for (i = 0; i < NOR; i++)
        for (j = 0; j < EMP; j++)
            mat[i][j] = 'N';
}

int cantEmp(char mat[NOR][EMP], int i, int j){
    if (i < NOR-1)
        if (j < EMP-1 && mat[i][j] == 'S')
            return cantEmp(mat, i, j+1);
        else 
            return mat[i][j] == 'S' + cantEmp(mat, i+1, 0);
    else
        return 0;
}

void eliminar(TListaC *LC, char MM[ST2], int N, char nom[NOR]){
    FILE *archB;
    struct {
        int numEmpresa, norma;
        char fechaCer[ST6];
    } elem;
    TListaC ant, act;
    subLista sAnt, sAct, sElim;

    if ((archB = fopen(nom, "wb"))==NULL)
        printf("No se pudo abrir el archivo \n");
    else {
        elem.norma = N;
        ant = *LC;
        act = (*LC)->sig;
        do{
            ant = act;
            act = act->sig;
        } while (act != (*LC)->sig && act->norma < N);
        if (act->norma == N){
            sAnt = NULL;
            sAct = act->sub;
            while (sAct != NULL){
                if (MM[0] == sAct->fechaCert[4] && MM[1] == sAct->fechaCert[5]){
                    sElim = sAct;
                    sAct = sAct->sig;
                    if (sAnt == NULL)
                        act->sub = sAct;
                    else
                        sAnt->sig = sAct;
                    strcmp(elem.fechaCer, sElim->fechaCert);
                    elem.numEmpresa = sElim->numEmp;
                    fwrite(&elem, sizeof(elem), 1, archB);
                    free(sElim);
                } else {
                    sAnt = sAct;
                    sAct = sAct->sig;
                }
            }
            if (act->sub == NULL){
                ant->sig = act->sig;
                if (act == *LC){
                    *LC = ant;
                    if (ant == act)
                        *LC = NULL;
                }

                free(act);
            }
        } else
            printf("No se ha encontrado la norma ingresada.\n");
        
        fclose(archB);
    }    
}