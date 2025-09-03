#define MAX 50
#define ST10 11
#define ST7 8
typedef struct {
    char fechaHora[ST10], patente[ST7];
}TElementoP;

typedef struct {
    TElementoP datos[MAX];
    int tope;
}TPila;

void poneP(TPila *P, TElementoP x);

void sacaP(TPila *P, TElementoP *x);


