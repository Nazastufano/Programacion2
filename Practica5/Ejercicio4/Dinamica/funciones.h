
typedef int TElementoC;

typedef struct nodoC{
    TElementoC dato;
    struct nodoC * sig;
} nodoC;

typedef struct {
    nodoC *pri, *ult;
} TCola;


void iniciaC(TCola *C);

void poneC(TCola *C, TElementoC x);

void sacaC(TCola *C, TElementoC *x);

TElementoC consultaC(TCola C);

int vaciaC(TCola C);