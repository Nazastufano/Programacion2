typedef int TElementoC;

typedef struct nodoC{
    TElementoC dato;
    struct nodoC *sig;
} nodoC;

typedef struct{
    nodoC *pri, *ult;
} TCola;

void iniciaC (TCola *C);

int vaciaC (TCola C);

TElementoC consultaC (TCola C);

void sacaC (TCola *C, TElementoC *x);

void poneC (TCola *C, TElementoC x);