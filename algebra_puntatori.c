
#include <stdio.h>
#include <stdlib.h>

//Scrivere un programma che chieda in input N numeri interi
//(con N definito dall’utente) e li me- morizzi in un vettore. 
//Calcolare la somma dei numeri interi inseriti usando unicamente l’aritmetica
//dei puntatori (non si deve quindi accedere al vettore con v[i]). 
//Stampare in output il valore della somma degli elementi del vettore.

int input(){
    int ret;
    printf("inserisci un numero: ");
    scanf("%d", &ret);
    return ret;
}

void costruisci(int *array,int n){
    int i;
    array = (int*)malloc(n*sizeof(int));
    printf("creazione array..\n");
    for(i = 0; i < n; i++){
        printf("array[%d] = ", i);
        scanf("%d", &array[i]);
    }
}

int somma_array(int *array,int n){
    int *i, ret = 0;
    for (i=array; i < array+n; i++){
        ret += *i; //somma usando algebra dei puntatori
                     //senza usare array[i]
    }
    return ret;
}

int main(){
    int n, *array, i;
    n = input();
    array = (int*)malloc(n*sizeof(int));
    printf("creazione array..\n");
    for(i = 0; i < n; i++){
        printf("array[%d] = ", i);
        scanf("%d", &array[i]);
    }


    //costruisci(array, n);
    printf("somma = %d \n", somma_array(array, n));
    free(array);
    return 0;
}
