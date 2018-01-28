#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h> 


void sleep(int secondi){ 
    time_t adesso,inizio; 
    inizio = adesso = time(NULL); 
    while(adesso<(inizio+secondi)){
        printf(".");
        adesso=time(NULL);
    } 
    printf("\n");
    return;
}

/*esercizio traccia 1Mar17*/
int matVerificato(int **matrice, int r, int c){
    int ret = 0, i, j,v;
    for (j = 0; j < c; j++){
        v = 1;
        for (i = 0; i < r; i++){
            if(matrice[i][j] < 58 || (matrice[i][j]%2) == 0)
                v = 0;
        }
        if(v != 0) ret++;
    }
    return ret;
}

int vetControllato(int **m, int *v, int K, int righe, int colonne){
    int ret = 0;
    int index, i, j, ver;
    if(K != righe) return -1;
    for (index = 0; index < righe ;index++){
        //cerco nella matrice 
        ver = 1;
        for(i = 0; i < K; i++){
            for(j = 0; j < colonne; j++){
                if(j==0 || j == 1 || j == 2){
                    if(m[index][j+3] < v[i])
                        ver = 0;
                }
                else if(j == colonne-1 || j == colonne - 2 || j == colonne - 3){
                    if(m[index][j-3] > v[i])
                        ver = 0;
                }
                else{
                    if(m[index][j-3] > v[i] && m[index][j+3] < v[i])
                        ver = 0;
                }
                if(ver) ret++;
            }
        }
    }
    return ret;
}

int** verifica_vet_matrice(int **matrice, int *vettore, int K, int r, int c){
    int **ret;
    ret = (int **)malloc(sizeof(int));
    ret[0] = (int *)malloc(sizeof(int));
    ret[0][0] = matVerificato(matrice, r, c);
    ret[0][1] = vetControllato(matrice, vettore, K, r, c);
    return ret;
}
//FINE ESERCIZIO TRACCIA.

int main(){
    int **matrice, i, j, dimR, dimC;
    int *vettore;
    //vettore di prova per il metodo vetControllato.
    int K = 3;
    vettore=(int*)malloc(3*sizeof(int));
    vettore[0]=1;
    vettore[1]=10;
    vettore[2]=75;

    /* int matrice[*rows][*columns];*/

    printf("al completamento delle richieste verrà creata una matrice.\n");
    printf("dimensione righe: ");
    scanf("%d", &dimR);

    printf("dimensione colonne:");
    scanf("%d", &dimC);
    if(dimR <= 0){
        printf("DIMENSIONE ERRATA");
        exit(1);
    }
    if(dimC <= 0){
        printf("DIMENSIONE ERRATA");
        exit(1);
    }

    matrice = (int**) malloc(dimR*sizeof(int*));
    for(i = 0; i < dimR; i++)
        matrice[i] = (int*) malloc(dimC*sizeof(int));

    printf("allocazione memoria..");
    sleep(dimR+dimC);
    printf("memoria allocata\n");
    

    for (i = 0; i < dimR; i++){
        for (j = 0; j < dimC; j++){
            printf("inserisci un valore nell'area di memoria:\n");
            scanf("%d", &matrice[i][j]);
        }
    }
    
    printf("Lettura dati inseriti: \n");
    for (i = 0;  i<dimR; i++){
        printf("%d:", i);
        for (j = 0; j < dimC; j++)
            printf("%5d", matrice[i][j]);
        printf("\n");
    }

    int** risultato = verifica_vet_matrice(matrice, vettore, K, dimR, dimC);
    
    printf("risultato: %d \t %d \n", risultato[0][0], risultato[0][1]);
    for(i = 0; i < dimR; i++)
        free(matrice[i]);
    free(matrice);

    free(risultato);

    return 0;
}
