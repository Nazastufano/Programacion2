#define MAX 50
#define ST25 26
#define ST6 7
typedef struct {
    char apeYNom[ST25], mailCont[ST25];
    char codPar[ST6];
}TElementoC;


typedef struct {
    TElementoC datos[MAX];
    int pri, ult;
}TCola;

void iniciaC(TCola *C);

void poneC(TCola *C, TElementoC x);

