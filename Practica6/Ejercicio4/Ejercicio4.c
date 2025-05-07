

/* 4. Corregir los errores en el siguiente programa, el cual incorpora en una lista ordenada de
números los elementos de un arreglo de N números ordenados, respetando el orden de la lista.

#define N 2
...
void main(){
    int i, arr[N] = {4,8,9,60}; // N = 2 y coloca 4 elementos
    TLISTA lista=NULL, pult=NULL, act, ant, nuevo; //pult está de mas
    cargarLista(&lista);
    printf("\nLista Original\n");
    muestra(&lista); //& esta de mas
    act = lista; //esta linea y la 15 van adentro del for
    ant = NULL;
    for(i=0; i<=N; i++) { //recorre una posion de mas
        while(act!=NULL && arr[i] <= act->n) { 
            act = ant; // asigna ant a actual
            act = act.sig; // es incorrecto ya que debe poner act->sig;
        }
        *nuevo = (TLISTA)malloc(sizeof(NODO)); //no necesita ser un puntero
        nuevo->n = arr[i-1]; //falla en el primer caso
        if(ant = NULL) { // esta asignado
            nuevo->sig = lista;
            *lista = &nuevo; //Esta mal, no va ni el *, ni tampoco & ya que lista y nuevo son el mismo tipo
        } else {
            nuevo->sig = ant; // nuevo->sig = act;
            ant->sig = &nuevo; // esta mal no va la direccion de memoria de nuevo ya que nuevo es puntero
        }
        act = nuevo->sig; //no va
    }
    printf("\nLista Resultado\n");
    muestra(&lista); // no necesita el &
} 
*/

#define N 4
...
void main(){
    int i, arr[N] = {4,8,9,60}; 
    TLISTA lista=NULL, act, ant, nuevo;
    cargarLista(&lista);
    printf("\nLista Original\n");
    muestra(lista);

    for(i=0; i<N; i++) {
        act = lista;
        ant = NULL;
        while(act != NULL && arr[i] <= act->n) { 
            ant = act;
            act = act->sig;
        }
        nuevo = (TLISTA)malloc(sizeof(NODO)); 
        nuevo->n = arr[i];
        nuevo->sig = act;
        if(ant == NULL) 
            lista = nuevo; 
        else 
            ant->sig = nuevo;
    }
      printf("\nLista Resultado\n");
    muestra(lista);
} 