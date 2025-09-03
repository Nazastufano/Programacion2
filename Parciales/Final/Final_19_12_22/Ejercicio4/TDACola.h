#define MAX 50

typedef struct {
    int id1, id2, cos;
}TElementoC;

typedef struct {
    TElementoC dato[MAX];
    int pri, ult;
}TCola;

void iniciaC(TCola *C);

void poneC(TCola *C, TElementoC x);

void sacaC(TCola *C, TElementoC *x);