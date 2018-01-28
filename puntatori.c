
#include <stdio.h>
#include <stdlib.h>

int int_input(){
    int ret;
    printf("inserisci un numero: ");
    scanf("%d", &ret); //scanf richiede un indirizzo nel quale inserire 
                        //l'input.
    return ret;
}


int main(){
    int a = int_input();
    int b = int_input();

    int *pa = NULL, *pb = NULL;
    printf("pa = %p\n", pa);
    printf("pb = %p\n", pb);

    pa = &a;
    pb = &b;

    printf("pa = %p\t valore = %d \n", pa, *pa);
    printf("pb = %p\t valore = %d \n", pb, *pb);
}
