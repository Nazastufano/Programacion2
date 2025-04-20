#define MAX 50

typedef struct {
    int numLegajo;
    int momentoArribo;
    int cantSegUsoHorno;
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