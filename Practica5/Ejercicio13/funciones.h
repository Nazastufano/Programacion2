#define MAX 50

typedef int TElementoC;

typedef struct {
    TElementoC datos[MAX];
    int pri, ult;
} TColaC;

void iniciaC(TColaC *C);

void poneC(TColaC *C, TElementoC x);

void sacaC(TColaC *C, TElementoC *x);

TElementoC consultaC(TColaC);

int vaciaC(TColaC C);
