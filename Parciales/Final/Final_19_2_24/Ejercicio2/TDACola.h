#define MAX 50
#define ST20 21
typedef struct {
    int idPlaylist;
    char idCancion[ST20];
}TElementoC;

typedef struct {
    TElementoC dato[MAX];
    int pri, ult;
}TCola;

void iniciaC(TCola *C);

void poneC(TCola *C, TElementoC x);

int vaciaC(TCola C);
