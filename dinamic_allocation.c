#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main(){
    int *array, dim, i;
    printf("inserisci dimensione: ");
    scanf("%d", &dim);

    array = malloc(dim*sizeof(int)); /*alloca dim celle di tipo intero */
    assert(array != NULL); /*fa apparire un messaggio di errore (stdlib.h)*/
    for(i = 0; i < dim; i++){
        printf("inserisci un elemento: ");
        scanf("%d", &array[i]);
    }

    printf("\nElementi allocati:\n");
    printf("\nElem\tindirizzo\tValore\n");
    for (i = 0; i < dim; i++)
        printf("%d \t%p \t%d\n", i, &array[i], array[i]);
    free(array);
    return 0;
}
