#define MAX 50

typedef int TELEMENTOC;

typedef struct {
    TELEMENTOC datos[MAX];
    int pri, ult;
} TCOLA;

void iniciac(TCOLA *C);

void ponec(TCOLA *C, TELEMENTOC x);

void sacac(TCOLA *C, TELEMENTOC *x);

TELEMENTOC consultac(TCOLA C);

int vaciac(TCOLA C);