
typedef char * TElementoP;

typedef struct nodo{
    TElementoP dato;
    struct nodo *sig;
}nodo;

typedef nodo * TPila;

void sacaP(TPila *P, TElementoP *X);
