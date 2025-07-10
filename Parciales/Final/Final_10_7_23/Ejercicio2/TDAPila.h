#define MAX 50

typedef struct {
    int H, C, D;
}TElementoP;

typedef struct{
    TElementoP datos[MAX];
    int tope;
}TPila;

void sacaP(TPila *P, TElementoP *x);