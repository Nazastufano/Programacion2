#define MAX 50

typedef struct {
    int V, G;
}TElementoP;

typedef struct {
    TElementoP datos[MAX];
    int tope;
}TPila;

void iniciaP(TPila *P);

void poneP(TPila *P, TElementoP x);

void sacaP(TPila *P, TElementoP *x);

int vaciaP(TPila P);