
typedef struct {
    char codigoAgente[6];
    char patente[8];
    int fechaJuliana;
    char horaMulta[6];
    int tiempoPagado;
    int tiempoRealOcupacion;
}TElementoC;

typedef struct nodoC{
    TElementoC datos;
    struct nodoC *sig;
} nodoC;

typedef struct {
    nodoC * pri, * ult;
}TCola;

void iniciaC(TCola *C);

void poneC(TCola *C, TElementoC x);

void sacaC(TCola *C, TElementoC *x);

int vaciaC(TCola C);

TElementoC consultaC(TCola C);