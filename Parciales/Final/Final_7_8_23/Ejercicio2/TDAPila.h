#define MAX 50

typedef struct {
    int E;
    char C;
} TElementoP;

typedef struct {
    TElementoP datos[MAX];
    int tope;
}TPila;

void poneP(TPila *P, TElementoP x);

void sacaP(TPila *P, TElementoP *x);