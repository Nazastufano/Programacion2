#define MAX 200

typedef struct {
    char codProd[8];
    int cantDispo;
}TElementoC;

typedef struct {
    TElementoC dato[MAX];
    int pri, ult;
}TCola;

int vaciaC(TCola C);

void sacaC(TCola *C, TElementoC *x);

