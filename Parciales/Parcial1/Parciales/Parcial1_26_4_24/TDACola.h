#define MAX 50

typedef struct {
    char dominio[8];
}TElementoC;

typedef struct {
    TElementoC dato[MAX];
    int pri, ult;
}TCola;

void iniciaC(TCola *C);

void sacaC(TCola *C, TElementoC *x);