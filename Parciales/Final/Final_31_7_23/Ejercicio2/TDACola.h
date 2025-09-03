#define MAX 50
#define ST5 6
typedef struct {
    char codLote[ST5];
}TElementoC;

typedef struct {
    TElementoC datos[MAX];
    int pri, ult;
}TCola;

void sacaC(TCola *C, TElementoC *x);