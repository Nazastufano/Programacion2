#define MAX 50

typedef struct {
    int num;
    int pos;
} TElementoP;

typedef struct {
    TElementoP dato[MAX];
    int tope;
} TPila;

void iniciaP(TPila *P);

void poneP(TPila *P, TElementoP x);

TElementoP consultaP(TPila P);