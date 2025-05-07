#define MAX 50

typedef struct {
    char nomJugador[20];
    char paloAnt;
    int puntos;
} TElementoC;

typedef struct {
    TElementoC datos[MAX];
    int pri, ult;
} TCola;

void iniciaC(TCola *C);

void poneC(TCola *C, TElementoC x);

void sacaC(TCola *C, TElementoC *x);

TElementoC consultaC(TCola C);

int vaciaC(TCola C);
