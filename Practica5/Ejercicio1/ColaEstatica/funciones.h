#define MAX 50

typedef int TElementoC;

typedef struct {
    TElementoC datos[MAX];
    int pri, ult; 
} TCola;

void iniciaC (TCola *C);

int vaciaC (TCola C);

TElementoC consultaC (TCola C);

void sacaC (TCola *C, TElementoC *x);

void poneC (TCola *C, TElementoC x);