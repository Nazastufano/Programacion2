typedef char TElementoP;

typedef struct nodoP{
    TElementoP dato;
    struct nodoP * sig;
} nodoP;

typedef nodoP * TPila;

void iniciaP(TPila *P);

void poneP(TPila *P, TElementoP x);

void sacaP(TPila *P, TElementoP *x);

TElementoP consultaP(TPila P);

int vaciaP(TPila P);