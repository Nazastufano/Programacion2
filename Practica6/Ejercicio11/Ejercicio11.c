
/* 11. Corregir los errores de la siguiente función, que elimina el nodo de una lista circular que 
contiene un valor pasado como parámetro (elem)

void lc_eliminaelem(TLISTAC *pult, TELEMENTOLC elem, int *eliminado) {//el nombre de la lista no es intuitivo
    TLISTAC ant, act = *pult->sig; 
    eliminado = 0; //*eliminado = 0
    if (pult = NULL) { //asigna y mal, deberia ser *pult != NULL
        do{ 
           ant = act;
           act->sig = act; //asigna invertido, act = act->sig;
        }while ( *pult != act && elem < act.dato); //act->dato, no dice si la lista esta ordenada, entonces elem != act->dato;
        
        if (elem = act->dato){ //asigna, deberia ser elem == act->dato, no consulta si *pult != act
            if (*pult != (*pult)->sig) //pregunta mal deberia ser act == pult->sig
                *pult = NULL; //pri
            else { 
                act->sig = ant->sig; //muevo //mal, debe ser ant->sig = act->sig
                if (act == *pult) //ult
                    pult = *ant; //mal, debe pult = ant;
            } 
            free (ant); //free(act)
            eliminado = 1; //*eliminado = 1
        } 
    } 
}  
*/

void lc_eliminaelem(TLISTAC *LC, TELEMENTOLC elem, int *eliminado) {//el nombre de la lista no es intuitivo
    TLISTAC ant, act = *LC->sig; 
    *eliminado = 0;
    
    if (*LC != NULL) { 
        do{ 
            ant = act;
            act = act->sig;
        }while (*LC != act && elem != act->dato); 
        
        if (*LC != act && elem == act->dato){
            if (*LC == (*LC)->sig)
                *LC = NULL; //un solo nodo
            else { 
                ant->sig = act->sig; //muevo
                if (act == *LC) //ult
                    *LC = ant;
            }
            free (act); 
            *eliminado = 1;
        } 
    } 
}  