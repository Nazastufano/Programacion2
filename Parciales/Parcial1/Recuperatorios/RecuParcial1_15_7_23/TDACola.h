#define MAX 100

typedef struct {
    int cantPasaj;
    char vip;
    char radio;
}TElementoC;

typedef struct {
    TElementoC dato[MAX];
    int pri, ult;
}TCola;

void iniciaC(TCola *C);

void sacaC(TCola *C, TElementoC *x);

void poneC(TCola *C, TElementoC x);

int vaciaC(TCola C);