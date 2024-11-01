#include <stdio.h>
#include <stdlib.h>

typedef struct arrayInicial
{
    int *p, *q;
    int tamanhoArray;
    int Vmax, Vmin;
    int sizePgh;
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

//varredura


arrayInicial createPgh (arrayInicial arr){
    arr.sizePgh = arr.Vmax - arr.Vmin + 1;

    arr.q =  (int*) malloc(arr.sizePgh * sizeof(int));

    for (int i=0; i < arr.sizePgh; i++){
        arr.q[i] = 1;
    }
    return arr;
}


int main(){
    arrayInicial arr;
    arr.p = NULL;
    arr.tamanhoArray = 0;
    arr = insercao(arr);

    arr.Vmax = arr.p[0];
    arr.Vmin = arr.p[1];
    //arr = varredura(arr);

    arr = createPgh(arr);

    printf("Array = { ");
    for(int t=0; t< arr.tamanhoArray; t++){
        printf("%d,", arr.p[t]);
    }
    printf("} \n");
    printf("Tamanho do Array: %d", arr.tamanhoArray);
    
    printf("\n Pigeonhole = { ");
    for(int t=0; t<arr.sizePgh; t++){
        printf("%d,", arr.q[t]);
    }
    printf("} \n");
}