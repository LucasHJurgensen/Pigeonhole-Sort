#include <stdio.h>
#include <stdlib.h>

typedef struct arrayInicial
{
    int *p;
    int tamanhoArray;
    int Vmax, Vmin;
}arrayInicial;


arrayInicial insercao(arrayInicial arr){
int i=0, r;
do{
        arr.p = (int*) realloc(arr.p, (i+1) * sizeof(int));
        printf("INSIRA UM VALOR NO ARRAY: ");
        scanf("%d", &arr.p[i]);

        i++;

        printf("Deseja inserir mais um valor?\n 1 - Sim   2 - Nao \n");
        scanf("%d", &r);
    } while (r!=2);

    arr.tamanhoArray = i;
    return arr;
}

int main(){
    arrayInicial arr;
    arr.p = NULL;
    arr.tamanhoArray = 0;
    arr = insercao(arr);

    arr.Vmax = arr.p[0];
    arr.Vmin = arr.p[0];
    arr = varredura(arr);

    printf("Array = { ");
    for(int t=0; t< arr.tamanhoArray; t++){
        printf("%d,", arr.p[t]);
    }
    printf("} \n");
    printf("Tamanho do Array: %d", arr.tamanhoArray);
}