#define MAX 50

typedef struct {
    char apellido[20];
    char nombre[20];
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